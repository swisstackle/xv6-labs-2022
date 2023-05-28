#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "sysinfo.h"
#include <stdint.h>

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  if(n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_trace(void)
{
	int arg;
	argint(0, &arg);
	if (arg < 0)
		arg = 0;
	myproc()->trace_arg = arg;
	return 0;
}

uint64
sys_sysinfo(void)
{
	struct sysinfo *user_pointer;
	struct sysinfo dst;
	argaddr(0, (void*)&user_pointer);
	if(user_pointer == 0)
		return -1;
	acquire(&myproc()->lock);
	pte_t *pagetable = myproc()->pagetable;
	release(&myproc()->lock);
	if(copyin(pagetable, (char*)&dst, (uint64)user_pointer, sizeof(struct sysinfo)) < 0)
		return -1;
	count_active_procs(&dst);
	dst.freemem = get_free_memory_size();
	acquire(&myproc()->lock);
	copyout(myproc()->pagetable, (uint64)user_pointer, (char*)&dst, sizeof(dst));
	release(&myproc()->lock);
	return 0;
}
