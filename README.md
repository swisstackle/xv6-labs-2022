# [MIT Opencourseware 6.828](https://github.com/swisstackle/6.828) Lab Solutions

## Lab 1: Xv6 and Unix Utilities

### Assignment 1: Sleep

Implement the UNIX program sleep for xv6; your sleep should pause for a user-specified number of ticks. A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip. Your solution should be in the file.

 [Solution](https://github.com/swisstackle/xv6-labs-2022/commit/10fc9f4af001937758101a8e3401d2b8d77b100b)

 ### Assignment 2: Pingpong

Write a program that uses UNIX system calls to ''ping-pong'' a byte between two processes over a pair of pipes, one for each direction. The parent should send a byte to the child; the child should print "<pid>: received ping", where <pid> is its process ID, write the byte on the pipe to the parent, and exit; the parent should read the byte from the child, print "<pid>: received pong", and exit. Your solution should be in the file

 [Solution](https://github.com/swisstackle/xv6-labs-2022/commit/c6bd4c94729772b315350a3da9635efe0d939e43)
 
 ### Assignment 3: Primes
 
 Write a concurrent version of prime sieve using pipes. This idea is due to Doug McIlroy, inventor of Unix pipes. The picture halfway down this page and the surrounding text explain how to do it. Your solution should be in the file user/primes.c. 
 
[Solution](https://github.com/swisstackle/xv6-labs-2022/commit/c6bd4c94729772b315350a3da9635efe0d939e43)

### Assignment 4: Find

Write a simple version of the UNIX find program: find all the files in a directory tree with a specific name. Your solution should be in the file user/find.c.

[Solution](https://github.com/swisstackle/xv6-labs-2022/commit/295767e2c34878f778d8ce03e128a78fb407df37)

Ulib.c C library functions were added for the find function to work: `strtrim` and `strcat`.

### Assignment 5: Xargs

Write a simple version of the UNIX xargs program: its arguments describe a command to run, it reads lines from the standard input, and it runs the command for each line, appending the line to the command's arguments. Your solution should be in the file user/xargs.c. 

[Solution](https://github.com/swisstackle/xv6-labs-2022/commit/87850aee8c4191f27bacc3cd7dca16cb5fab241c)

## Lab 2: System Calls

### Assignment 1: Use gdb

See https://pdos.csail.mit.edu/6.828/2022/labs/syscall.html

[Solution](https://github.com/swisstackle/xv6-labs-2022/commit/0516d5d9c75951d1abccf2b142f0537dc9a6eb5d)

### Assignment 2: System call tracing

In this assignment you will add a system call tracing feature that may help you when debugging later labs. You'll create a new trace system call that will control tracing. It should take one argument, an integer "mask", whose bits specify which system calls to trace. For example, to trace the fork system call, a program calls trace(1 << SYS_fork), where SYS_fork is a syscall number from kernel/syscall.h. You have to modify the xv6 kernel to print out a line when each system call is about to return, if the system call's number is setin the mask. The line should contain the process id, the name of the system call and the return value; you don't need to print the system call arguments. The trace system call should enable tracing for the process that calls it and any children that it subsequently forks, but should not affect other processes.

[Solution](https://github.com/swisstackle/xv6-labs-2022/commit/ab3b3a71e900fa5fd11cbcb7347a26816e2d7989)

### Assignment 3: Sysinfo

In this assignment you will add a system call, sysinfo, that collects information about the running system. The system call takes one argument: a pointer to a struct sysinfo (see kernel/sysinfo.h). The kernel should fill out the fields of this struct: the freemem fieldshould be set to the number of bytes of free memory, and the nproc field should be set to the number of processes whose state is not UNUSED. We provide a test program sysinfotest; you pass this assignment if it prints "sysinfotest: OK".

[Solution](https://github.com/swisstackle/xv6-labs-2022/commit/a7e2c7bcb9906cf47f6949e98378aa161136ca10)

## Build & Test
You can hit either `make qemu` to start the OS or hit `make grade` to test all the labs with testcases.
You can also hit `./grade-lab-util sleep` and replace `sleep` with any of the labnames to test each lab individually.


