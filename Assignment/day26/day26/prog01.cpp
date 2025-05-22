/*Digital Clock Simulation*/
#include<iostream>
using namespace std;
class DigitalClock {
private:
	int hour;
	int minute;
	int second;
public:
	void sethour(int h) {
		hour = h;
	}
	int gethour() {
		return hour;
	}
	void setminute(int m) {
		minute = m;
	}
	int getminute() {
		return minute;
	}
	void setsecond(int s) {
		second = s;
	}
	int getsecond() {
		return second;
	}

	void tick() {
		second++;
		if (second == 60) {
			second = 0;
			minute++;
		}if (minute == 60) {
			minute = 0;
			hour++;
		}if (hour == 24) {
			hour = 0;
		}
	}
	void display() {
		cout << hour << ":" << minute << ":" << second<< endl;
	}

};
int main() {
	int h, m, s;
	cin >> h >> m >> s;
	DigitalClock d;
	d.sethour(h);
	d.setminute(m);
	d.getsecond(s);
	d.tick();
	d.display();
}