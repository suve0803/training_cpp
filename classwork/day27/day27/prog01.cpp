#include<iostream>
#include<string>
using namespace std;
class item {
private:
	int iid;
	char iname[20];
	float iprice;
	int iquantity;
public:
	void setiid(int i) {
		iid = i;
	}
	int getiid() {
		return iid;
	}
	void setiname(char* n) {
		strcpy(iname, n);
	}
	char* getiname() {
		return iname;
	}
	void setiprice(float p) {
		iprice = p;
	}
	float getiprice() {
		return iprice;
	}
	void setiquantity(int q) {
		iquantity = q;
	}
	int getiquantity() {
		return iquantity;
	}
	void display() {
		cout << "Enter item id: " << endl;
		cout << "Enter item name: " << endl;
		cout << "Enter item price: " << endl;
		cout << "Enter item quantity: " << endl;

	}
	bool additem(int i,char* n, float p, int q) {
		iid = i;
		iname = n;
		iprice = p;
		iquantity = q;
	}
};