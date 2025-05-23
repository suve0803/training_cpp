/*Flight Seat Reservation System*/

#include<iostream>
#include<string>
using namespace std;

class Flight {
private:
	string flightnumber;
	int totalseats;
	int bookedseats;
public:
	void setflightnumber(string n) {
		flightnumber = n;
	}
	string getflightnumber() {
		return flightnumber;
	}
	void settotalseats(int s) {
		totalseats = s;
	}
	int gettotalseats() {
		return totalseats;
	}
	void setbookedseats(int s) {
		bookedseats = s;
	}
	int getbookedseats() {
		return bookedseats;
	}
	bool bookSeats(int seats) {
		if (seats > 0 && bookedseats + seats <= totalseats) {
			bookedseats =bookedseats+seats;
			return true;
		}
		return false; 
	}
	int showavailability() {
		int availability = totalseats - bookedseats;
		return availability;
	}
	void display() {
		cout << "Flight: " << flightnumber << "|" << "Seat Available: " << showavailability() << endl;;
			
	}

};



int main() {

	Flight f1;
	f1.setflightnumber("AI203");
	f1.settotalseats(100);
	f1.setbookedseats(0);

	if (f1.bookSeats(30)) {
		cout << " "<<endl;
	}
	else {
		cout << "Booking Failed"<<endl;
	}
	f1.display();


	if (f1.bookSeats(80)) {
		cout << " " << endl;
	}
	else {
		cout << "Booking Failed: Not enough seats." << endl;
	}
	return 0;
}

