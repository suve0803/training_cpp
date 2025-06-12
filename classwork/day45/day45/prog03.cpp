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

//class task {
//private:
//	std::string id;
//	int load;
//public:
//	task(std::string id,int load):id(id),load(load){}
//};
class TaskQueue {
private:
	std::queue<task> t;
	std::mutex m;
	std::condition_variable cv;
public:
	void push(task t1) {
		{
			std::lock_guard<std::mutex>lock(m);
			t.push(t1);
		}
		cv.notify_one();
	}

	bool pop(task& t1) {
		std::lock_guard<std::mutex> lock(m);
		if (t.empty()) {
			return false;
		}
		t1 = t.front();
		t.pop();
		return true;
	}
	bool isempty() {
		std::lock_guard<std::mutex>lock(m);
		return t.empty();
	}
	void waitForTask() {
		std::lock_guard<std::mutex> lock(m);
		

	}
};

void cpuWorker(int cpuId, TaskQueue& tq) {
	while (true) {
		task t;

		tq.waitForTask();
		if (!tq.pop(t)) {
			break; 
		}

		std::cout << "CPU-" << cpuId << " picked Task " << t.id << " (Load: " << t.load <<std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(t.load));
		std::cout << "CPU-" << cpuId << " finished Task " << t.id << std::endl;
	}
}
int main() {
	std::ifstream inputfile("input.txt");
	if (!inputfile.is_open()) {
		std::cout << "Error in opening a input.txt file " << std::endl;
	}

}
