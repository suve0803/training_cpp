/*Area of circle*/
#include<iostream>
using namespace std;
int main() {
	float pi = 3.14;
	float radius;
	float area;
	cout << "Enter the radius: " << endl;
	cin >> radius;
	area = ((pi)*radius * radius);
	cout << "Area of circle : " << area;
}