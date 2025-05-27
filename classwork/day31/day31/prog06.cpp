#include<iostream>
using namespace std;
class Vehicle {
protected:
	//int vehicle;
	int tyres;
	//string fueltype;
	int seats;
	string material;
	string color;
	string modeOfCrtl;
public:
	Vehicle(int tyres,int seats,string material,string color,string modeOfCtrl) {
		
		this->tyres = tyres;
		this->seats = seats;
		this->material = material;
		this->color = color;
		this->modeOfCrtl = modeOfCrtl;
	}
	void display1() {
		cout << tyres << "\t" << seats << "\t" << material << "\t" << color << "\t" << modeOfCrtl << endl;
	}
};

class Car :public Vehicle {
private:
	string brand;
	string fuelType;
	int doors;
	float price;
	string variant;
	string model;
public:
	Car(int tyres, int seats, string material, string color, string modeOfCtrl,string brand, string fuelType, int doors, float price, string variant, string model):Vehicle(tyres,seats,material,color,modeOfCrtl) {
		this->brand = brand;
		this->fuelType = fuelType;
		this->doors = doors;
		this->price = price;
		this->variant = variant;
		this->model = model;
	}
	void display2() {
		cout << brand << "\t" << fuelType << "\t" << doors << "\t" << price << "\t" << variant << "\t" << model << endl;
	}
};