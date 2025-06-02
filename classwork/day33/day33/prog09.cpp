#include<iostream>
using namespace std;
template<class T,class T2>
class Calculator {
private:
	T1 v1;
	T2 v2;
	
public:
	Calculator(T1 v1,T2 v2):v1(v1),v2(v2){}
	float add() {
		return v1 + v2;
	}
	float sub() {
		return v1 - v2;
	}
	double Mul() {
		return v1 * v2;
	}
	double Div() {
		if (v2 != 0) {
			return v1 / v1;
		}
		else {
			cout << "Error" << endl;
			return 0;
		}
	}
	

	void display() {
		cout << "value 1: " << v1 << endl;
		cout << "value 2:" << v2 << endl;
	}

};
int main() {
	Calculator<int,float> intCalc(10, 5.7);
	intCalc.display();
	cout << "Addition: " << intCalc.add() << endl;
	cout << "Subtraction: " << intCalc.sub() << endl;
	cout << "Multiplication: " << intCalc.Mul() << endl;
	cout << "Division: " << intCalc.Div() << endl;

	
	return 0;
}