#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main() {
	vector<int>numbers = { 10,20,30 };
	for(auto it=numbers.begin();it!=numbers.end();it++)
		cout << *it << " ";
}