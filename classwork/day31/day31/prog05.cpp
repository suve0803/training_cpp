#include<iostream>
using namespace std;
class Nums {
protected:
	int n1, n2;
public:
	void setNums(int n1,int n2) {
		this->n1 = n1;
		this->n2 = n2;
	}
};

class Multiplier:public Nums {
private:
	int prod;
public:
	void setValues() {
		cout << "Enter n1 and n2: " << endl;
		cin >> n1 >> n2;
	}
	int multiply() {
		prod = n1 * n2;
		return prod;
	}
};

int main() {
	Multiplier mobj;
	mobj.setValues();
	cout << mobj.multiply() << endl;
	return 0;
}
