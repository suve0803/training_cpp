#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
bool flag = true; 
void printPingPong(const std::string& word, bool isPing) {
    for (int i = 0; i < 10; ++i) {
        while (true) { 
            m.lock(); 
            if (flag == isPing) {
                std::cout << word <<std::endl;
                flag = !flag;
                m.unlock();
                break; 
            }
            m.unlock();
        }
    }
}

int main() {
    
    std::thread t1(printPingPong, "Ping", true);  
    std::thread t2(printPingPong, "Pong", false);
    t1.join();
    t2.join();

    return 0;
}
