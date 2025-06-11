#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<iterator>

using namespace std;

int main() {
	vector<int> vec = { 10,20,30,40,50 };

	cout << "Using normal iterator: " << endl;
	vector<int>::iterator it;
	for (it = vec.begin();it != vec.end();it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "Using reverse iterator:" << endl;
	for (auto rit = vec.rbegin();rit != vec.rend();rit++) {
		cout << *rit << " ";
	}
	cout << endl;
	cout << "Using const_iterator(read-only): " << endl;
	for (vector<int>::const_iterator cit = vec.cbegin();cit != vec.cend(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
	cout << "Doubling each element: " << endl;
	for (auto it = vec.begin();it != vec.end();it++) {
		*it *= 2;
		cout << *it << " ";
	}
	cout << endl;
	list<string>names = { "Suve","Nivi","Kavi","Pavi" };
	auto lit = names.begin();
	advance(lit, 2);
	cout << "2nd index in list: " << *lit << endl;
	auto prevIt = std::prev(lit);
	std::cout << "Previous element: " << *prevIt << endl;
	std::cout << "Distance from start to lit: " << std::distance(names.begin(), lit) << endl;
	std::set<int> s = { 100, 200 };
	std::copy(vec.begin(), vec.end(), std::inserter(s, s.begin()));
	std::cout << "Set after inserting vector elements: "<<endl;
	for (int x : s) std::cout << x << " ";
	std::cout << endl;
	std::cout << "Using ostream_iterator to print vector: "<<endl;
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << endl;

	return 0;
}

