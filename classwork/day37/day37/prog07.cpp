#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    std::vector<int>scores;
    int score;
    cout << "Enter scores : ";
    while (true) {
        cin >> score;
        if (score == -1)
            break;
        scores.push_back(score);
    }
    std::sort(scores.begin(), scores.end(), [](int a, int b) {
        return a > b;
        });

    cout << "Scores(desending Sorted) : ";
    for (size_t i = 0; i < scores.size(); i++) {
        std::cout << scores[i] << " ";
    }
    cout << endl;
    std::sort(scores.begin(), scores.end(), [](int a, int b) {
        return a < b;
        });

    cout << "Scores(Ascending Sorted) : ";
    for (size_t i = 0; i < scores.size(); i++) {
        std::cout << scores[i] << " ";
    }
    cout << endl;
    std::cout << "Top 3 Scores: ";
    for (size_t i = 0; i < 3 && i < scores.size(); i++) {
        std::cout << scores[i] << " ";
    }
    return 0;
}