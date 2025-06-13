#include<iostream>
using namespace std;
class Aution {
private:
	string itemName;
	float minPrice;
	float maxPrice;
	string highestBidder;
public:
	Aution(string itemName, float minPrice, float maxPrice, string highestBidder){
		this->itemName = itemName;
		this->minPrice = minPrice;
		this->maxPrice = maxPrice;
		this->highestBidder = highestBidder;
	}
	void display() {
		cout << "itemName: " << itemName << "Minimum Price: " << minPrice << "Maximum Price: " 
			<< maxPrice << "Highest Bidder: " << highestBidder << endl;
	}
	void placeBid( string& bidderName, double bidAmt) {
		if (bidAmt < minPrice) {
			cout << "Bid rejected!" << endl;
		}
		else if (bidAmt <= maxPrice) {
			cout << "Bid rejected!" << endl;
		}
		highestBidder = bidAmt;
		highestBidder = bidderName;
		cout << "Bid Accepted" << bidderName << "is a highest bidder " << bidAmt << endl;
	}
	
};

int main()
{
	Aution a("suve")
}