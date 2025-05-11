/* Write a program in C++ to find the area and circumference of a circle. */
#include<iostream>
# define PI 3.14
using namespace std;
int main() {
	float r;
	cin >> r;
	cout << "Area of a circle: " << PI * r * r << endl;
	cout << "Circumference of a circle: "<<2 * PI * r<<endl;
}