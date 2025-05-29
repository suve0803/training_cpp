/*A vehicle company is deciding to hire a programmer to develop a system that will allow the
company to enter the details of the vehicles sold by them. As a programmer, you need to
implement a program that contains a base class called Vehicles that contains a data
member to store the price of the vehicles. Derive two other classes named as Car and
Motorcycle.
• The Car class will contain data members to store details that include seating capacity,
number of doors and fuel type (diesel or petrol).
• The Motorcycle class will contain data members to store details such as the number
of cylinders, the number of gears and the number of wheels.
Derive another subclass named as Audi of Car and Yamaha of Motorcycle.
• The Audi class will contain a data member to store the model type.
• The Yamaha class will contain a data member to store the make – type.
Display the details of an Audi car (price, seating capacity, number of doors, fuel type, model
type) and the details of the Yamaha motorcycle (price, number of cylinders, number of
gears, number of wheels, make – type)*/
#include<iostream>
using namespace std;
class Vehicles {
protected:
    float price;
public:
    Vehicles(float p) {
        price = p;
    }
 
};
class Car :public Vehicles {
protected:
    int seatingCap;
    int doors;
    string fuelType;
public:
    Car(float p,int d, int seatCap, string fType) :Vehicles(p) {
        doors = d;
        seatingCap = seatCap;
        fuelType = fType;
    }
    void dispCar() {
        cout << "Price: " << price << endl;
        cout << "Seating Capacity: " << seatingCap << endl;
        cout << "Doors: " << doors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};
class Bike :public Vehicles {
protected:
    int no_Cylinders;
    int no_gears;
    int wheels;
public:
    Bike(float p, int c, int g, int w) :Vehicles(p) {
        no_Cylinders = c;
        no_gears = g;
        wheels = w;
    }
    void dispBike() {
        cout << "Price: " << price << endl;
        cout << " Number of cylinders" << no_Cylinders << endl;
        cout << "Number of Gears: " << no_gears << endl;
        cout << "Number of Wheels" << wheels << endl;
    }
};
class Audi :public Car {
protected:
    string modelType;
public:
    Audi(string mType, float p, int d, int seatCap, string fType) :Car(p, d, seatCap, fType) {
        modelType = mType;
    }
    void dispAudi() {
        dispCar();
        cout << "Model Type: " << modelType << endl;
    }
};
class Yamaha : public Bike {
private:
    string makeType;
public:
    Yamaha(string make_T, float p, int c, int g, int w) :Bike(p, c, g, w) {
        makeType = make_T;
   }
    void dispYamaha()  {
        dispBike();
        cout << "Make Type: " << makeType << endl;
    }
};
int main() {
    Audi a("H4",50000, 5, 4, "Petrol");
    cout << "Audi Car Details:" << endl;
    a.dispAudi();

    cout << endl;

    // Create a Yamaha motorcycle object
    Yamaha y("ERT2",150000, 2, 6, 2);
    cout << "Yamaha Motorcycle Details:" << endl;
    y.dispYamaha();

    return 0;
}
