/* Print Numbers from N to 1 */


#include<iostream>
using namespace std;

int printnumbers(int n) {
	if (n < 1) {
		return 1;
	}
	cout << n<<" ";
	printnumbers(n - 1);
}



int main() {
	int N;
	cin >> N;
	printnumbers(N);
	return 0;
}