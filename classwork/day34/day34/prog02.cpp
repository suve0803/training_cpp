#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
string line;
ifstream fIn("Tables.exe");
if (!fIn.is_open())
cerr << "Error:Opening a file" << endl;
while (getline(fIn, line))
cout << line << endl;
fIn.close();

}
