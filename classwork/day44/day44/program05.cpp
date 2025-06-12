/*Print "ABC" Using Three Threads
Problem Statement:
Create three threads to print "A", "B", and "C" respectively in strict sequence. The final output should be:
ABCABCABC... repeated 5 times.

Constraints:

Each thread should print only its assigned character.*/
#include<iostream>
#include<thread>
#include<mutex>
std::mutex m;
void display(char c) {
	static int count = 0;
	for (int i = 0; i < 5;)
	{
		m.lock();
		if (count % 3 == 0 && c == 'A')
		{
			std::cout << c;
			i++;
			count++;
		}
		else if (count % 3 == 1 && c == 'B')
		{
			std::cout << c;
			i++;
			count++;
		}
		else if (count % 3 == 2 && c == 'C')
		{
			std::cout << c;
			i++;
			count++;
		}
		m.unlock();
	}
}
int main() {
	std::thread t1(display, 'A');
	std::thread t2(display, 'B');
	std::thread t3(display, 'C');
	t1.join();
	t2.join();
	t3.join();
	return 0;
}