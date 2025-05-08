#include<iostream>
using namespace std;
int main() {
	char str1[100] = { 0 };
	cin.getline(str1, 100);
	char res[100];
	int i = 0;
	int k=0;
	while (str1[i] != '\0') {
		char str2[100];
		int j = 0;
		while (str1[i] != ' ' && str1[i] != '\0') {
			str2[j++] = str1[i++];
		}
		str2[j] = '\0';
		for (int l = j - 1;l >= 0;l--) {
			res[k++] = str2[l];
		}
		if (str1[i] == ' ') {
			res[k++] = ' ';
			i++;
		}
	}
	res[k] = '\0';
	cout << res << endl;
	return 0;
}