#include <iostream>
#include <thread>
using namespace std;

void backgroundTask() {
    std::this_thread::sleep_for(std::chrono::seconds(30));
    std::cout << "Background task done." << std::endl;
}
void disp(int& x) {

}

int main() {
    int x = 10;
    std::thread t(backgroundTask);
    t.detach(); // Main won't wait
    std::cout << "Main is not blocked.\n";
    std::this_thread::sleep_for(std::chrono::seconds(50)); // Wait to see output

    thread t1(disp, ref(x));//call by referrence
    cout << "val: " << x << endl;
    return 0;
}