#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> age = { {"Alice", 30}, {"Bob", 25} };

    for (auto it = age.begin(); it != age.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}