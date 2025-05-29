#include<iostream>
using namespace std;
class Vehicle {
protected:
    string v_id;
    string type;
    float ratePerKm;
private:
    Vehicle(string v_id, string type, float ratePerKm) {
        this->v_id = v_id;
        this->type = type;
        this->ratePerKm = ratePerKm;
    }
    void dispVehicle() {

        cout << "Vehicle Type: " << type << endl;
        cout << "Vehicle ID: " << v_id << endl;
        cout << "Rate per Km: " << ratePerKm << endl;
    }
};
class Car :public Vehicle{
public:
    Car(string v_id, string type, float ratePerKm,string id, float rate) : Vehicle( type,id, ratePerKm) {}
    float calculate(float distance) {
        return distance * ratePerKm;
    }
};