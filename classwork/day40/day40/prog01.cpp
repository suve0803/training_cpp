#include<iostream>
#include<string>
#include<exception>
using namespace std;
class BadLengthException {
private:
	int n;
public:
	BadLengthException(int error) {
		n = error;
	}int what() {
		return n;
	}
};
bool checkUsername(string username) {
	bool isvalid = true;
	int n = username.length();
	if (n<5) {
		throw BadLengthException(n);

	}
	for (int i = 0;i < n - 1;i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isvalid = false;
		}
	}
	return isvalid;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string username;
		cin >> username;
	
	try {
		bool isValid = checkUsername(username);
		if (isValid) {
			cout << "Valid" << endl;
		}
		else {
			cout << "Invalid" << endl;
		}
	}
	catch (BadLengthException e) {
		cout << "Too short: " << e.what() << endl;
	}
	}
	return 0;
}


