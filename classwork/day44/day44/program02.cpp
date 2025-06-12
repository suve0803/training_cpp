/*2. Print Odd and Even Numbers Using Same Function
Problem: Write a program using two threads running the same function to print odd and even numbers 
from 1 to N. Use a flag to distinguish between threads.

Objective: Learn how to pass arguments to threads and reuse the same function logic with different behavior.*/

#include<iostream>
#include<thread>
void print(int n,int start) {
	
	for (int i = start;i <= n;i++) {

			if (i % 2 == start) {
				std::cout << i << std::endl;
			}
	}
}
int main() {
	int n;
	std::cin >> n;
	std::thread t1(print,n, 0);
	t1.join();
	std::thread t2(print,n, 1);
	t2.join();
	return 0;
}