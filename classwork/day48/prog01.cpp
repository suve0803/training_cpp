#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<sstream>
#include<mutex>

using namespace std;

class CDRRecord {
	string MSISDN;
	string Brand;
	string msd;
	//string callType;
	string MOC;
	string MTC;
	string SMS_MO;
	string SMS_MT;
	string GPRS;
	/*int duration;
	double download;
	double upload;*/

	CDRRecord(string& MSISDN,string& Brand,string& msd,
		string& MOC,string MTC,string SMS_MO,string SMS_MT,string GPRS):
		MSISDN(MSISDN),Brand(Brand),msd(msd),MOC(MOC),MTC(MTC),
		SMS_MO(SMS_MO),SMS_MT(SMS_MT),GPRS(GPRS){}
};
class CDRProcessor {
private:
    vector<CDRRecord> records;

public:
    void parseCDRFile(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string msisdn, operatorBrand, operatorMNC, callType, thirdPartyMSISDN, thirdPartyOperatorMNC;
            int duration;
            double download, upload;

            getline(ss, msisdn, '|');
            getline(ss, operatorBrand, '|');
            getline(ss, operatorMNC, '|');
            getline(ss, callType, '|');
            ss >> duration;
            ss.ignore(1, '|');
            ss >> download;
            ss.ignore(1, '|');
            ss >> upload;
            ss.ignore(1, '|');
            getline(ss, thirdPartyMSISDN, '|');
            getline(ss, thirdPartyOperatorMNC);

            records.emplace_back(msisdn, operatorBrand, operatorMNC, callType, duration, download, upload,
                thirdPartyMSISDN, thirdPartyOperatorMNC);
        }
    }
};

stringstream s1(line);
