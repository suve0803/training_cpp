/*4. Print Characters Alternately (Ping Pong)
Problem: Create two threads. One prints "Ping" and the other prints "Pong" alternately 10 times. 
Ensure the output is in the correct alternating sequence.

Objective: Understand thread synchronization using condition variables or atomic flags.*/

#include<iostream>
#include<thread>
#include<mutex>
void printPing() {

}
void printPong() {

}

int main() {
	std::thread t1(printPing);
	std::thread t2(printPong);
}