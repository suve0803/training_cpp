#include<iostream>
#include<thread>
#include<mutex>
#include<fstream>
#include<string>
#include<chrono>
#include<queue>
#include<condition_variable>
//using namespace std;
struct task {
	std::string id;
	int load;
};

class TaskQueue{
private:
	std::queue<task> t;
	std::mutex m;
	std::condition_variable cv;
public:
	void push(task t1) {
		std::lock_guard<std::mutex>lock(m);
		t.push(t1);
	}
	cv.notify_one();
}