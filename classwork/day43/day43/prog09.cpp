#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> tasks = { "Eat", "Code", "Sleep" };
    for (auto rit = tasks.rbegin(); rit != tasks.rend(); ++rit)
        cout << *rit << " -> ";  
}