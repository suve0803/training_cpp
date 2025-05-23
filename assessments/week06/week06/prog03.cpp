/*Food Delivery Tip Calculator*/
#include<iostream>
using namespace std;
class DeliveryTip {
private:
	string OrderId;
	int BillAmount;
	int Distance;
	int Tip;
public:
	void setOrderId(string i) {
		OrderId = i;
	}
	string getOrderId() {
		return OrderId;
	}
	void setBillAmount(float b) {
		BillAmount = b;
	}
	float getBillAmount() {
		return BillAmount;
	}
	void setDistance(float d) {
		Distance = d;
	}
	float getDistance() {
		return Distance;
	}
	void setTip(float t) {
		Tip = t;
	}
	float getTip() {
		return Tip;
	}
	void calculateTip() {
		if (Distance < 5) {
			Tip = BillAmount * 0.05;
		}
		else if (Distance <= 10) {
			Tip = BillAmount * 0.10;
		}
		else {
			Tip = BillAmount * 0.15;
		}
	}
	void printDetails() {

calculateTip(); 
cout << "Order" <<getOrderId() <<" | Tip: " <<getTip() << endl;

}

};

int main() {

DeliveryTip d1;

 

d1.setOrderId("ORD1");

d1.setBillAmount(500);

d1.setDistance(3);

d1.printDetails();



DeliveryTip d2;

d2.setOrderId("ORD2");

d2.setBillAmount (1000);

d2.setDistance(12);

d2.printDetails();
	
}
