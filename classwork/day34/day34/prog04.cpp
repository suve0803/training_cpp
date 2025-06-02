#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("sample.txt", ios::binary);
    file.seekg(3, ios::beg); // Move to beginning
    cout << "File size: " << file.tellg() << " bytes\n";
    char ch;
    file.get(ch);
    cout << "character at that position: " << ch << endl;

    file.seekg(-3, ios::cur); // Move at current position
    cout << "File size: " << file.tellg() << " bytes\n";
    char ch1;
    file.get(ch1);
    cout << "character at that position: " << ch1 << endl;

    file.seekg(-1, ios::end); // Move to end
    cout << "File size: " << file.tellg() << " bytes\n";
    char ch2;
    file.get(ch2);
    cout << "character at that position: " << ch2 << endl;

    file.close();
    return 0;
}