##  Looking at the backtrace output, which function called syscall? 
usertrap() in kernel/trap.c

##  What is the value of p->trapframe->a7 and what does that value represent? (Hint: look user/initcode.S, the first user program xv6 starts.) 
The value is `7` and it represents the `exec` system call number. `initcode.S` sets the `a7` register to be `7` so and then executes the system call with `ecall`.

##  What was the previous mode that the CPU was in?

Currently, we are in supervisor mode. The `SPP bit` of `sstatus` is set to `0` which means that we were in usermode prior to getting into supervisor mode.

##  Write down the assembly instruction the kernel is panicing at. Which register corresponds to the varialable num? 
This is the corresponding asm instruction:
```
num = * (int *) 0;
    80001ffc:	00002683          	lw	a3,0(zero) # 0 <_entry-0x80000000>
```
Since we are trying to dereference the memory location `0`, the kernel panics. The corresponding register is `a3`.

## Why does the kernel crash? Hint: look at figure 3-3 in the text; is address 0 mapped in the kernel address space? Is that confirmed by the value in scause above? (See description of scause in RISC-V privileged instructions) 

Address 0 is not mapped in the kernel address space.
THe Trap Cause Code is `0x000d` which means that store access fault occured.

## What is the name of the binary that was running when the kernel paniced? What is its process id (pid)? 
`p->name` had value 'initcode\000\000\000\000\000\000\000'
