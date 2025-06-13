#include<iostream>
#include<thread>
#include<mutex>
#include<fstream>
#include<string>
#include<chrono>
#include<queue>
#include<sstream>
#include<condition_variable>
//using namespace std;
//struct task {
//	std::string id;
//	int load;
//};

class task {
private:
	std::string id;
	int load;
public:
	task(std::string id,int load):id(id),load(load){}
	std::string getId() const {
		return id;
	}

	int getLoad() const {
		return load;
	}
    bool isvalid() const {
        return !id.empty();
    }

};
class TaskQueue {
private:
	std::queue<task> t;
	std::mutex m;
	std::condition_variable cv;
public:
	void pushT(task t1) {
		{
			std::lock_guard<std::mutex>lock(m);
			t.push(t1);
		}
		cv.notify_one();
	}

	task popT(task t1) {
		std::lock_guard<std::mutex> lock(m);
		if (t.empty()) {
			return ;
		}
		t1 = t.front();
		t.pop();
		return t1;
	}
	
	void waitForTask() {
		while(true){
		std::lock_guard<std::mutex> lock(m);
		if (!t.empty()) {
			return;
		}
		}
	}

};
class LoadBalancer {
public:
public:
    LoadBalancer(const std::string& filename) {
        readTasksFromFile(filename);
    }

    void start(int cpuCount) {
        for (int i = 1; i <= cpuCount; ++i) {
            cpus.emplace_back(&LoadBalancer::cpuWorker, this, i);
        }
        for (auto& cpu : cpus) {
            cpu.join();
        }

        std::cout << "All tasks completed."<<std::endl;
    }

private:
    std::vector<std::thread> cpus;
    TaskQueue tq;

    void readTasksFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file."<<std::endl;
            exit(1);
        }

        std::string line;
        int cpuCount = 0;
        std::getline(inputFile, line);
        std::istringstream(line.substr(6)) >> cpuCount;
        while (std::getline(inputFile, line)) {
            std::string taskId = line.substr(0, line.find(':'));
            int load = std::stoi(line.substr(line.find_last_of(' ') + 1));
            tq.pushT(task(taskId, load));
        }

        inputFile.close();
    }

    void cpuWorker(int cpuId) {
        while (true) {
            task t1 ; 
            tq.waitForTask();
            tq.popT(t1);
            if (!t1.isvalid()) {
                break; 
            }

            std::cout << "CPU-" << cpuId << t1.getId() << " (Load: " << t1.getLoad() << ")"<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(t1.getLoad()));
            std::cout << "CPU-" << cpuId << " finished Task " << t1.getId() <<std::endl;
        }
    }
};



int main() {
    LoadBalancer lb("input.txt");
    lb.start(3); 
    return 0;
	}
	



