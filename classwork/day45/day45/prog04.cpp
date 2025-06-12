#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>
#include <chrono>
#include <queue>
#include <sstream>
#include <condition_variable>
#include <vector>

class Task {
private:
    std::string id;
    int load;

public:
    Task(std::string id, int load) : id(id), load(load) {}

    std::string getId() const {
        return id;
    }

    int getLoad() const {
        return load;
    }

    bool isValid() const {
        return !id.empty();
    }
};

class TaskQueue {
private:
    std::queue<Task> tasks;
    std::mutex mtx;
    std::condition_variable cv;

public:
    void pushTask(const Task& t) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(t);
        }
        cv.notify_one();
    }

    bool popTask(Task& t) { // Changed to pass by reference
        std::lock_guard<std::mutex> lock(mtx);
        if (tasks.empty()) {
            return false;
        }
        t = tasks.front();
        tasks.pop();
        return true;
    }

    void waitForTask() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !tasks.empty(); });
    }
};

class LoadBalancer {
private:
    TaskQueue tq;
    std::vector<std::thread> cpus;

    void readTasksFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file." << std::endl;
            exit(1);
        }

        std::string line;
        int cpuCount = 0;
        std::getline(inputFile, line);
        std::istringstream(line.substr(6)) >> cpuCount;

        while (std::getline(inputFile, line)) {
            std::string taskId = line.substr(0, line.find(':'));
            int load = std::stoi(line.substr(line.find_last_of(' ') + 1));
            tq.pushTask(Task(taskId, load));
        }

        inputFile.close();
    }

    void cpuWorker(int cpuId) {
        while (true) {
            tq.waitForTask();

            Task t;
            if (!tq.popTask(t) || !t.isValid()) {
                break;
            }

            std::cout << "CPU-" << cpuId << " processing Task " << t.getId()
                << " (Load: " << t.getLoad() << ")" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(t.getLoad()));
            std::cout << "CPU-" << cpuId << " finished Task " << t.getId() << std::endl;
        }
    }

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

        std::cout << "All tasks completed." << std::endl;
    }
};

int main() {
    LoadBalancer lb("input.txt");
    lb.start(3);
    return 0;
}
