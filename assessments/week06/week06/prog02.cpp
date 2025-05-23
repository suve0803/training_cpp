/*Hotel Room Booking Manager*/
#include<iostream>
using namespace std;
class HotelRoom {
private:
	int RoomNumber;
	string Type;
	bool Isbooked;
public:
	void setRoomNumber(int n) {
		RoomNumber = n;
	}
	int getRoomNumber() {
		return RoomNumber;
	}
	void setType(string t) {
		Type = t;
	}
	string getType() {
		return Type;
	}
	void setIsbooked(bool b) {
		Isbooked = b;
	}
	bool getIsbooked() {
		return Isbooked;
	}
	void bookrooms() {
		if (getIsbooked()) {
			cout << "Room is already booked."<<endl;
		}
		else {
			setIsbooked(true);
			cout << "Room " << getRoomNumber() << " (" << getType() << ") is now booked.\n";
		}
	}
	/*void ShowStatus() {
		cout << "Room " << getRoomNumber() << "(" << getType() << ") is" << "booked." << "available." << endl;
	}*/
	
};
int main() {

	HotelRoom h1;
	h1.setRoomNumber(201);
	h1.setType("AC");
	h1.setIsbooked(false);
	h1.bookrooms();        
	//h1.ShowStatus();      
	
	h1.bookrooms();       
	//h1.ShowStatus();

	return 0;


}

