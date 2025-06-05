/*std::vector<string> – Batch Word Processing*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector <string> fruits = { "Apple", "banana", "apple", "Orange", "BANANA", "grape" };

	for (auto& fruit : fruits)
		cout << fruit << endl;
	

	for (auto& fruit : fruits)
		transform(fruit.begin(), fruit.end(), fruit.begin(), ::tolower);

	sort(fruits.begin(), fruits.end(), [](string s1, string s2) { 
		return  s1 < s2;
		});

	auto newEnd = unique(fruits.begin(), fruits.end());

	fruits.erase(newEnd, fruits.end());

	for (auto& fruit : fruits)
		cout << fruit << endl;
	
	return 0;

}
