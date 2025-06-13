#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <mutex>
#include <thread>
#include <chrono>

// Auction class
class Auction {
private:
    std::string itemName;
    double minPrice;
    double highestBid;
    std::string highestBidder;
    std::mutex auctionMutex;

public:
    Auction(const std::string& itemName, double minPrice)
        : itemName(itemName), minPrice(minPrice), highestBid(0), highestBidder("None") {}

    bool placeBid(const std::string& bidderName, double bidAmount, std::ofstream& logFile) {
        std::lock_guard<std::mutex> lock(auctionMutex);

        if (highestBidder == "CLOSED") {
            logFile << "Auction is closed. Bid rejected for item: " << itemName << "\n";
            return false;
        }
        if (bidAmount <= highestBid || bidAmount < minPrice) {
            logFile << "Bid too low. Bid rejected for item: " << itemName << "\n";
            return false;
        }

        highestBid = bidAmount;
        highestBidder = bidderName;
        logFile << "Bid placed! " << bidderName << " is leading with $" << bidAmount << " on item: " << itemName << "\n";
        return true;
    }

    void closeAuction(std::ofstream& logFile) {
        std::lock_guard<std::mutex> lock(auctionMutex);

        if (highestBidder == "CLOSED") {
            logFile << "Auction already closed for item: " << itemName << "\n";
            return;
        }

        if (highestBidder == "None") {
            logFile << "Auction closed for item: " << itemName << ". No bids placed.\n";
        }
        else {
            logFile << "Auction closed for item: " << itemName << ". Winner: " << highestBidder << " with bid: $" << highestBid << "\n";
        }

        highestBidder = "CLOSED"; // Marks the auction as closed
    }
};

// AuctionManager class
class AuctionManager {
private:
    std::map<std::string, Auction> auctions;
    std::ofstream logFile;

public:
    AuctionManager(const std::string& logFileName) {
        logFile.open(logFileName, std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "Error opening log file.\n";
            exit(1);
        }
    }

    ~AuctionManager() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void addAuction(const std::string& auctionID, const std::string& itemName, double minPrice) {
        auctions[auctionID] = Auction(itemName, minPrice);
        logFile << "Auction added: " << itemName << " (ID: " << auctionID << ") with minimum price $" << minPrice << "\n";
        std::cout << "Auction added successfully!\n";
    }

    void placeBid(const std::string& auctionID, const std::string& bidderName, double bidAmount) {
        if (auctions.find(auctionID) != auctions.end()) {
            auctions[auctionID].placeBid(bidderName, bidAmount, logFile);
        }
        else {
            std::cout << "Invalid auction ID. Bid not placed.\n";
        }
    }

    void startAuctionTimer(const std::string& auctionID, int seconds) {
        if (auctions.find(auctionID) == auctions.end()) {
            std::cout << "Invalid auction ID. Timer not started.\n";
            return;
        }

        std::thread([this, auctionID, seconds]() {
            std::this_thread::sleep_for(std::chrono::seconds(seconds));
            auctions[auctionID].closeAuction(logFile);
            }).detach();
    }

    void viewLog() {
        std::ifstream log("auction_log.txt");
        if (!log.is_open()) {
            std::cout << "Error opening log file.\n";
            return;
        }
        std::string line;
        while (getline(log, line)) {
            std::cout << line << "\n";
        }
    }
};

// Simple CLI
void auctionCLI() {
    AuctionManager manager("auction_log.txt");
    int choice;

    do {
        std::cout << "\n1. Add Auction\n2. Place Bid\n3. Start Auction Timer\n4. View Logs\n5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string id, name;
            double price;
            std::cout << "Enter Auction ID: ";
            std::cin >> id;
            std::cout << "Enter Item Name: ";
            std::cin.ignore();
            getline(std::cin, name);
            std::cout << "Enter Minimum Price: ";
            std::cin >> price;
            manager.addAuction(id, name, price);
        }
        else if (choice == 2) {
            std::string id, bidder;
            double amount;
            std::cout << "Enter Auction ID: ";
            std::cin >> id;
            std::cout << "Enter Bidder Name: ";
            std::cin >> bidder;
            std::cout << "Enter Bid Amount: ";
            std::cin >> amount;
            manager.placeBid(id, bidder, amount);
        }
        else if (choice == 3) {
            std::string id;
            int duration;
            std::cout << "Enter Auction ID: ";
            std::cin >> id;
            std::cout << "Enter Timer Duration (in seconds): ";
            std::cin >> duration;
            manager.startAuctionTimer(id, duration);
        }
        else if (choice == 4) {
            manager.viewLog();
        }
        else if (choice == 5) {
            std::cout << "Exiting... Goodbye!\n";
        }
        else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

// Main function
int main() {
    auctionCLI();
    return 0;
}