// System call numbers
#define SYS_fork    1
#define SYS_exit    2
#define SYS_wait    3
#define SYS_pipe    4
#define SYS_read    5
#define SYS_kill    6
#define SYS_exec    7
#define SYS_fstat   8
#define SYS_chdir   9
#define SYS_dup    10
#define SYS_getpid 11
#define SYS_sbrk   12
#define SYS_sleep  13
#define SYS_uptime 14
#define SYS_open   15
#define SYS_write  16
#define SYS_mknod  17
#define SYS_unlink 18
#define SYS_link   19
#define SYS_mkdir  20
#define SYS_close  21
#define SYS_trace  22

// System call names for dynamic syscall_names array generated in kernel/syscall.c. Will eventually do the same for the system call function table in kernel/syscall.c to make things more modular and less "editive". Note: trace is not included because the names array is// for the trace system call itself.
#define SYSTEM_CALLS \
    X(fork) \
    X(exit) \
    X(wait) \
    X(pipe) \
    X(read) \
    X(kill) \
    X(exec) \
    X(fstat) \
    X(chdir) \
    X(dup) \
    X(getpid) \
    X(sbrk) \
    X(sleep) \
    X(uptime) \
    X(open) \
    X(write) \
    X(mknod) \
    X(unlink) \
    X(link) \
    X(mkdir) \
    X(close) \
	X(trace)
