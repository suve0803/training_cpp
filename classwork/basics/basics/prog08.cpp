#include<iostream>

using namespace std;
int main() {
	char str[100];
	int count = 0;
	cout << "Enter a string: " << endl;
	cin.getline(str, 100);
	for (int i = 0;str[i] != '/0';i++){
	char ch=str[i];
	if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
		count++;
	}
	
}cout << "The num of vowels are : " << count << endl;
}