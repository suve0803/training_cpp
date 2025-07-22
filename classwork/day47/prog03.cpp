#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>oddno;
	auto odd = [](int n, vector<int>& no) {
		for (int i = 0;i < n;i++) {
			if (i % 2 != 0)
				no.emplace_back(i);
			cout << i << endl;
		}
		};
	/*auto odd = [](int n) {for (int i = 0;i <= n;i++)if (i % 2 != 0)cout<< i<<endl;};
	odd(10);*/
}