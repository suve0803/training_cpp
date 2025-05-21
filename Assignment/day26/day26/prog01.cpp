/*Digital Clock Simulation*/
#include<iostream>
using namespace std;
class DigitalClock {
private:
	int hour;
	int minute;
	int second;
public:
	void sethour(int h=0) {
		hour = h;
	}
	int gethour() {
		return hour;
	}
	void setminute(int m=0) {
		minute = m;
	}
	int getminute() {
		return minute;
	}
	void setsecond(int s=0) {
		second = s;
	}
	int getsecond() {
		return second;
	}

	void tick() {

	}

};