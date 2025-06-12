#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void incrementCounter(int n) {
    for (int i = 0; i < n; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

int main() {
    const int numThreads = 5;
    const int increments = 1000;
    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(incrementCounter, increments);
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    std::cout << "Final Counter Value: " << counter << std::endl;

    return 0;
}