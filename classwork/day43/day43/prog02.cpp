#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main() {
	istream_iterator<int>inIt(std::cin);
	istream_iterator<int>endIt;

	vector<int>numbers(inIt, endIt);
	vector<int>num = { 1,2,3 };
	for (int n : numbers) {
		cout << n << " " << endl;
	}
	ostream_iterator<int>outIt(cout, "|");
	copy(numbers.begin(),numbers.end())
	return 0;
}