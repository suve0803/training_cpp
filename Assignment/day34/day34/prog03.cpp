#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<thread>
using namespace std;
enum logLevel {
	INFO = 0,
	DEBUG,
	WARNING,
	ERROR,
};
class Logger {
	ofstream fileOut;
public:
	Logger(char* f1) {
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
	}
	const char* logleveltostring(int level) {
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
class Job {
protected:
	int JobID;
	int executionTime;
	int priority;
public:
	void setId(int JobID) {
		this->JobID = JobID;
	}
	int getId() {
		return JobID;
	}
	void setExecTime(int executionTime)
	{
		this->executionTime = executionTime;
	}
	int getExecTime()
	{
		return executionTime;
	}
	void setPriority(int priority)
	{
		this->priority = priority;
	}
	int getPriority()
	{
		return priority;
	}
	void display() {
		cout << "Job ID: " << JobID << endl;
		cout << "execution Time: " << executionTime << endl;
		cout << "Priority: " << priority << endl;
	}
	int executeJob(Logger& obj) {
		auto start = chrono::system_clock::now();
		this_thread::sleep_for(chrono::milliseconds(executionTime));
		auto end = chrono::system_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
		char msg[100];
		sprintf(msg, "Executing Job ID: %d | Priority: %d | ExecTime %dms", JobID, priority, duration.count());
		obj.log(1, msg);
		return duration.count();
	}
};
struct Compare
{
	bool operator()(Job obj1, Job obj2)
	{
		return obj1.getPriority() < obj2.getPriority();
	}
};

class Queue
{
protected:
	vector<Job>arr;
	int totalTime;
	bool isPriority;
public:
	Queue()
	{
		Job j;
		totalTime = 0;
		int val;
		isPriority = false;
		ifstream inFile;
		try
		{
			inFile.open("job.txt", ios::in);
			if (!inFile.is_open())
				throw "File cannot be opened";
		}
		catch (const char* s)
		{
			cout << s << endl;
			exit(0);
		}
		while (!inFile.eof())
		{
			inFile >> val;
			j.setId(val);
			inFile >> val;
			j.setExecTime(val);
			inFile >> val;
			j.setPriority(val);
			arr.push_back(j);
		}
	}


	void sortPriority()
	{
		sort(arr.begin(), arr.end(), Compare());
	}

	void executeQueue(Logger& obj)
	{
		if (isPriority == true)
		{
			sortPriority();
		}
		for (auto i : arr)
		{
			totalTime += i.executeJob(obj);
		}
	}

	int getTotTime()
	{
		return totalTime;
	}

	void setPriority(bool isPriority)
	{
		this->isPriority = isPriority;
	}
};
