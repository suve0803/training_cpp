#include<iostream>
using namespace std;
bool isprime(int);
int main() {
	int number;
	cout << "Enter the number: ";
	cin >> number;
	if (number <= 2) {
		cout << "No of possible ways: ";
	}
	int ways = 0;
	for (int i = 2;i <= number;i++) {
		if (isprime(i) && isprime(number-1)) {
			cout << number << "=" << i << "+" << number - 1;
			ways++;
		
		}
	}
	

}





bool isprime(int num) {
	if (num <= 1)
		return false;
	for (int i = 2;i * i <= num;i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}