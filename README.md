# MITOpencoursware 6.828 Labs

## Lab 1: Xv6 and Unix Utilities

## Assignment 1: Sleep

Implement the UNIX program sleep for xv6; your sleep should pause for a user-specified number of ticks. A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip. Your solution should be in the file.

 [Solution](https://github.com/swisstackle/xv6-labs-2022/commit/10fc9f4af001937758101a8e3401d2b8d77b100b)

 ## Assignment 2: Pingpong

Write a program that uses UNIX system calls to ''ping-pong'' a byte between two processes over a pair of pipes, one for each direction. The parent should send a byte to the child; the child should print "<pid>: received ping", where <pid> is its process ID, write the byte on the pipe to the parent, and exit; the parent should read the byte from the child, print "<pid>: received pong", and exit. Your solution should be in the file

 [Solution](https://github.com/swisstackle/xv6-labs-2022/commit/c6bd4c94729772b315350a3da9635efe0d939e43)
 
 ## Assignment 3: Primes
 
 Write a concurrent version of prime sieve using pipes. This idea is due to Doug McIlroy, inventor of Unix pipes. The picture halfway down this page and the surrounding text explain how to do it. Your solution should be in the file user/primes.c. 
 
[Solution](https://github.com/swisstackle/xv6-labs-2022/commit/c6bd4c94729772b315350a3da9635efe0d939e43)
