#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> 
using namespace std;
int main() {
    array<int, 10> grades = { 78, 92, 35, 44, 89, 55, 67, 29, 49, 100 };
    cout << "Original Grades (Reverse Order): ";
    for (array<int, 10>::reverse_iterator rit = grades.rbegin(); rit != grades.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
    for (array<int, 10>::iterator it = grades.begin(); it != grades.end(); ++it) {
        if (*it < 40) {
            *it = 40; 
        }
    }
    cout << "Grades after fixing failures: ";
    for (int g : grades) cout << g << " ";
    cout << endl;
    int pass_count = 0;
    for (std::array<int, 10>::const_iterator cit = grades.cbegin(); cit != grades.cend(); ++cit) {
        if (*cit >= 50) pass_count++;
    }
    std::cout << "Number of students who passed: " << pass_count << endl;
    std::sort(grades.begin(), grades.end());

    std::cout << "Sorted Grades: ";
    for (int g : grades) std::cout << g << " ";
    std::cout << endl;

    return 0;
}