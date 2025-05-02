#include<iostream>
#define SIZE 50
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[SIZE];
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	int res = 1;
	for (int i = 0;i < n;i=i+2) {
		if (i < n && arr[i]!= arr[i + 1]) {
			res = arr[i];
			break;
		}
	}if (res == 1) {
		res = arr[n - 1];

	}
	cout << res << endl;
	return 0;
}


/*output

9
1 1 2 2 3 4 4 5 5
3

11
0 0 1 1 2 2 6 6 7 7 9
9

5
-10 -10 -3 -3 0
0

7
3 3 4 4 5 5 7
7

*/