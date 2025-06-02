#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ofstream fOut("Tables.txt",ios::trunc|ios::app);
	/*for (int i = 0;i < 10;i++) {
		fOut << i + 1 <<"x"<<"2"<<"="<<2*(i+1) << endl;
	}*/
	fOut << "Name:" << endl;
	fOut.close();
}