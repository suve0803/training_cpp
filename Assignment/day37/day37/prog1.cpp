#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
int godNumber(const T& s) {
    int frequency[10] = { 0 };

  
    for (auto ch : s) {
        if (ch >= '0' && ch <= '9') {
            frequency[ch - '0']++;
            
        }
    }

    int maxDefinite = 0; 
    int minDefinite = 1000; 

    for (int i = 0; i <= 9; i++) {
        if (frequency[i] > 0) {
            int definiteValue = i * frequency[i];
            maxDefinite = max(maxDefinite, definiteValue);
            minDefinite = min(minDefinite, definiteValue);
        }
    }

    if (maxDefinite == minDefinite) {
        return maxDefinite;
    }

    return maxDefinite - minDefinite;
}

int main() {
    string s;
    cin >> s;

    cout << godNumber(s) << endl;

    vector<char> chars(s.begin(), s.end());
    cout << "God Number : " << godNumber(chars) << endl;

    return 0;
}