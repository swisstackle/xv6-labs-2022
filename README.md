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

## Build & Test
You can hit either `make qemu` to start the OS or hit `make grade` to test all the labs with testcases.
You can also hit `./grade-lab-util sleep` and replace `sleep` with any of the labnames to test each lab individually.


