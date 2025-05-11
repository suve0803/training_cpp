#include<iostream>
using namespace std;
int main() {
	int start, end;
	cin >> start >> end;
	if (start % 2 !=0){
		start++;
	}

	for (int i = start;i <= end;i+=2) {
		cout << i << " ";
	}
	return 0;
}