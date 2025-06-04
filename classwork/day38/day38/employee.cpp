#include<iostream>
#include<list>
#include"employee.h"
using namespace std;
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
	listemp.remove(s2);
	for(auto l)

}