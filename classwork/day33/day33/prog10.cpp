//Exception handling
#include<iostream>
using namespace std;
int main() {
	string error = "Suvetha";
	string dbyzeroErr = "Divide by zero error occured";
	string nullptrErr = "Memory allocation failed";
	char* ptr = nullptr;
	int n1 = 10, n2 = 0;
	try {
		/*if (n2 == 0)
			throw dbyzeroErr;*/
		/*if (ptr == nullptr)
			throw nullptrErr;*/
		//float res = n1 / n2;
		int* arr = new int[99999999999];
		if (arr == nullptr) 

		throw arr;
	}
	catch (int e) {
		cout << "caught an Exception: "<<e << endl;
	}
	catch (string e) {
		cout << "caught an Exception: " << e << endl;
	}
	catch (bad_alloc& e) {
		cout << "Error(bad_alloc): " << e.what() << endl;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}