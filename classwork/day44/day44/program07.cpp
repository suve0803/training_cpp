#include<iostream>
#include<thread>
#include<mutex>
#include<string>


std::mutex mtx;
void printFB(std::string s, int n, int tNo)
{
	for (static int i = 1; i <= n;)
	{
		std::lock_guard<std::mutex> lock(mtx);
		if (i == n + 1)
			break;
		if (tNo == 3 && i % 3 == 0 && i % 5 == 0)
		{
			std::cout << s << std::endl;
			i++;
		}
		if (tNo == 1 && i % 3 == 0 && i % 5 != 0)
		{
			std::cout << s << std::endl;
			i++;

		}
		if (tNo == 2 && i % 5 == 0 && i % 3 != 0)
		{
			std::cout << s << std::endl;
			i++;

		}
		if (tNo == 4 && i % 5 != 0 && i % 3 != 0)
		{
			std::cout << i << std::endl;
			i++;

		}
	}
}

int main()
{
	std::thread t1(printFB, "Fizz", 20, 1);
	std::thread t2(printFB, "Buzz", 20, 2);
	std::thread t3(printFB, "FizzBuzz", 20, 3);
	std::thread t4(printFB, "", 20, 4);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}