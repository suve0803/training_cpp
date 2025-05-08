#include<iostream>
using namespace std;
int main(int argc,char*argv[]) {
	string shape;
	if (argc > 1) {
		shape = argv[1];
	}
	else {
		cout << "Enter the shape: ";
		cin >> shape;
	}if (shape == "triangle") {
		float b, h;
		if (argv[4]) {
			
		}
	}
	
}

int triangle(float b,float h) {
	return b * h;

}
int rectangle(float l,float w) {
	return l * w;
}
int square(float s) {
	return s * s;

}
int circle(float r) {
	char pi = 3.14;
	return pi * (r * r);

}