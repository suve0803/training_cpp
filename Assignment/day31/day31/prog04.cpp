#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleId;
    string type;
    float ratePerKm;

public:
    Vehicle(string id, string type, float rate) {
        this->vehicleId = id;
        this->type = type;
        this->ratePerKm = rate;
    }

    void dispV() {
        cout << "Vehicle Type: " << type << ", Vehicle ID: " << vehicleId << ", Rate: " << ratePerKm << "/km" << endl;
    }
};


class Car : public Vehicle {
public:
    Car(string id, float rate) : Vehicle(id, "Car", rate) {}

    float calculateFare(float distance) {
        return distance * ratePerKm;
    }

   
    float calculateFare(float distance, int days) {
        float fare = distance * ratePerKm;
        if (days > 2) {
            fare -= fare * 0.10;  
        }
        return fare;
    }
};


class Bike : public Vehicle {
public:
    Bike(string id, float rate) : Vehicle(id, "Bike", rate) {}

 
    float calculateFare(float distance) {
        return distance * ratePerKm;
    }

    float calculateFare(float distance, int days) {
        float fare = distance * ratePerKm;
        if (days > 2) {
            fare -= fare * 0.10;  
        }
        return fare;
    }
};

int main() {
  
    string vehicleType = "Car";
    string vehicleId = "C100";
    float ratePerKm = 15;
    float distance = 100;
    int days = 3;

    Car car(vehicleId, ratePerKm);

    cout << "Vehicle Information: "<<endl;
    car.dispV();


    float fareWithoutDiscount = car.calculateFare(distance);
    float fareWithDiscount = car.calculateFare(distance, days);


    cout << "Fare without discount: " << fareWithoutDiscount << endl;
    cout << "Fare with long-term discount: " << fareWithDiscount << endl;

    return 0;
}