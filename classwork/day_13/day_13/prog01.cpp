#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char line[] = "This is CPP Programming Class";
	char ch = 'C';
		char* res = strchr(line, ch);
		if (res != nullptr)
			cout << "\t" << res << endl;
		else
			cout << "character not found" << endl;
		char substr[] = "s";
		char* res1 = strstr(line, substr);
		if(res!=nullptr)

}