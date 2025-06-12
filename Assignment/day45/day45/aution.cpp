#include<iostream>
#include<string>
class Aution {
private:
	int itemID;
	double minPrice;
	double maxPrice;
	std::string highestBidder;
public:
	Aution(int itemID, double minPrice, double maxPrice, std::string highestBidder){
	}
	void showAution() {
		std::cout << "itemID: " << itemID << "Minimum Price: " << minPrice << "Maximum Price: " 
			<< maxPrice << "Highest Bidder: " << highestBidder << std::endl;
	}
	bool placeBid(const std::string& bidderName, double bidAmt) {
		if (bidAmt < minPrice) {

		}
	}
};