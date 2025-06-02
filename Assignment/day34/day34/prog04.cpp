#include <iostream>
#include<fstream>
#include<vector>
#include<thread>
#include<string>
using namespace std;
enum logginglevels {
	INFO,
	DEBUG,
	WARNING,
	ERROR
};
class logger {
	ofstream fileOut;
public:
	logger(char* f1) {
		try {
			fileOut.open(f1, ios::app);
			if (!fileOut.is_open()) {
				throw"Error in opening file";
			}
		}
		catch (string s) {
			cout << s;
			exit(0);

		}
	}const char* logleveltostring(int level) {
		switch (level) {
		case INFO:
			return "INFO";
			break;
		case DEBUG:
			return "DEBUG";
		case WARNING:
			return "WARNING";
		case ERROR:
			return "ERROR";
		default:
			break;
		}
	}
	void log(int level, char* str) {
		fileOut << "[" << logleveltostring(level) << "]" << str << endl;
	}
};
class Packet {
	int packetID;
	string protocol;
	int size;
public:
	void setPacketID(int packetID) {
		this->packetID = packetID;
	}
	int getPacketID() {
		return packetID;
	}
	void setProtocol(string protocol) {
		this->protocol = protocol;
	}
	string protocol() {
		return protocol;
	}
	void size(int size) {
		this->size = size;
	}
	int size()
};