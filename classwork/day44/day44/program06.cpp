/* Odd-Even Alternating Print Using Threads
Problem Statement:
Create two threads, one to print odd numbers and one to print even numbers from 1 to 20 in order:
1 2 3 4 ... 20

Constraints:

The odd thread prints 1, 3, 5...

The even thread prints 2, 4, 6...

The output must be strictly in sequence.

Objective: Practice coordination of threads based on numeric condition and alternating turns.
*/

#include<iostream>
#include<thread>
#include<mutex>
