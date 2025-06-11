#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores = { 10, 20, 30 };
    for (auto it = scores.begin(); it != scores.end(); ++it)
        *it += 10;
    for (vector<int>::const_iterator it = scores.cbegin(); it != scores.cend(); ++it)
        cout << *it << " ";  
}