#include<iostream>
#include<list>
#include<algorithm>
#include"employee.h"
using namespace std;


	/*void my_sort(std::list<employee>&list, bool (*compare)(const employee&, const employee&)) {
		if (list.size() <= 1) {
			return;
		}

		for (auto it = std::next(list.begin()); it != list.end(); it++) {
			employee key = *it;
			auto j = it;
			while (j != list.begin() && compare(*std::prev(j), key)) {
				*j = *std::prev(j);
				j--;
			}
			*j = key;
		}
	}*/

void mysort(list<employee>&ls) {
	for (auto& i : ls) {
		for (auto& j : ls) {
			if (i < j) {
				auto t = i;
				i = j;
				j = t;
			}
			
		}


	}
}


int main() {
	employee s1(101, "abc1");
	employee s2(102, "abc2");
	employee s3(103, "abc3");
	employee s4(104, "abc4");
	std::list<employee>listemp;
	listemp.push_front(s1);
	listemp.push_back(s2);
	listemp.emplace_front(s3);
	listemp.emplace_back(s4);
	listemp.insert(listemp.begin(),s2);

	/*cout << "Employee after insersion: ";
	for((int ls : listemp) cout << ls << " ";
		std::cout << "\n";)*/
	cout << "Employee list after insersion: " << endl;

	for (auto ls : listemp)
		ls.display();
	cout << endl;
	listemp.reverse();
	for (auto ls : listemp)
		ls.display();

	cout << endl;
	listemp.remove(s2);
	for (auto ls : listemp)
		ls.display();

	cout << endl;

	mysort(listemp);

	for (auto ls : listemp)
		ls.display();

	//listemp.sort();
	//for (auto ls : listemp)
	//	ls.display();

}