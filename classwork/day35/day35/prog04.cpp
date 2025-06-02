#include <iostream>
#include <chrono>

int main() {
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);

    std::cout << "Current time: " << std::ctime(&timeNow);

    auto start = std::chrono::high_resolution_clock::now();

    // Simulated work
    for (int i = 0; i < 1000000; ++i);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution Time: " << duration.count() << " microseconds\n";
}