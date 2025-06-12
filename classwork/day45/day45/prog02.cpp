#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
//using namespace std;
std::condition_variable cv;
std::mutex m;
bool ready = false;
void worker() {
	std::unique_lock<std::mutex>lock(m);
	cv.wait(lock, [] {return ready;});
	std::cout << "Thread processing." << std::endl;
}
void notifier() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	{
		std::lock_guard<std::mutex>lock(m);
		ready = true;
	}
	cv.notify_one();
}
int main() {
	std::thread t1(worker);
	std::thread t2(notifier);
	t1.join();
	t2.join();
	return 0;
}