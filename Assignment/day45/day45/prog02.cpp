#include <iostream>
#include <thread>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <mutex>
#include <set>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

class User {
public:
    string userId;
    string name;
    User(string id, string n) : userId(id), name(n) {}
    virtual void menu() = 0;
    virtual ~User() = default;
};

class Buyer : public User {
public:
    Buyer(string id, string name) : User(id, name) {}
    void menu() override {
        cout << "Buyer Menu: You can place bids.\n";
    }
};

class Seller : public User {
public:
    Seller(string id, string name) : User(id, name) {}
    void menu() override {
        cout << "Seller Menu: You can create auctions.\n";
    }
};

class Bid {
public:
    string bidderId;
    double amount;
    chrono::system_clock::time_point timestamp;

    Bid(string id, double amt)
        : bidderId(id), amount(amt), timestamp(chrono::system_clock::now()) {}

    bool operator<(const Bid& other) const {
        return amount < other.amount;
    }
};

class Auction {
public:
    string itemId;
    string sellerId;
    double minPrice;
    bool active;
    priority_queue<Bid> bids;
    set<string> activeBidders;
    mutex auctionMutex;
    chrono::system_clock::time_point endTime;

    Auction(string item, string seller, double price, int durationSeconds)
        : itemId(item), sellerId(seller), minPrice(price), active(true) {
        endTime = chrono::system_clock::now() + chrono::seconds(durationSeconds);
    }

    bool isActive() {
        lock_guard<mutex> lock(auctionMutex);
        return active && chrono::system_clock::now() < endTime;
    }

    void placeBid(const Bid& bid) {
        lock_guard<mutex> lock(auctionMutex);
        if (isActive() && bid.amount >= minPrice) {
            bids.push(bid);
            activeBidders.insert(bid.bidderId);
            cout << "Bid placed: " << bid.bidderId << " -> $" << bid.amount << endl;
            logBid(bid);
        }
        else {
            cout << "Bid rejected for item " << itemId << endl;
        }
    }

    void closeAuction() {
        lock_guard<mutex> lock(auctionMutex);
        if (!active) return;
        active = false;

        try {
            ofstream file("results.txt", ios::app);
            if (!file) {
                throw runtime_error("Failed to open results.txt");
            }
            file << "Auction Closed for Item: " << itemId << "\n";
            if (!bids.empty()) {
                Bid topBid = bids.top();
                file << "Winner: " << topBid.bidderId << " with $" << topBid.amount << "\n";
            }
            else {
                file << "No bids received.\n";
            }
        }
        catch (const exception& e) {
            cerr << "Error writing auction results: " << e.what() << endl;
        }
    }

    void logBid(const Bid& bid) {
        try {
            ofstream log("bids_log.txt", ios::app);
            if (!log) {
                throw runtime_error("Failed to open bids_log.txt");
            }
            auto time = chrono::system_clock::to_time_t(bid.timestamp);
            log << "Item: " << itemId << ", Bidder: " << bid.bidderId
                << ", Amount: " << bid.amount << ", Time: " << ctime(&time);
        }
        catch (const exception& e) {
            cerr << "Error logging bid: " << e.what() << endl;
        }
    }
};

unordered_map<string, Auction*> auctions;
mutex globalMutex;

void auctionScheduler() {
    while (true) {
        this_thread::sleep_for(chrono::seconds(5));
        vector<string> toClose;

        // Collect auctions to close
        {
            lock_guard<mutex> lock(globalMutex);
            for (const auto& auc : auctions) {
                if (!auc.second->isActive()) {
                    toClose.push_back(auc.first);
                }
            }
        }

        // Close auctions outside the lock
        for (const string& id : toClose) {
            auctions[id]->closeAuction();
        }
    }
}

void listActiveAuctions() {
    lock_guard<mutex> lock(globalMutex);
    cout << "\nActive Auctions:\n";
    for (const auto& auc : auctions) {
        if (auc.second->isActive()) {
            cout << "Item: " << auc.first << ", Min Price: $" << auc.second->minPrice << "\n";
        }
    }
}

int main() {
    thread scheduler(auctionScheduler);
    scheduler.detach();

    cout << "Welcome to OAP_SIM\n";
    string id, name, role;
    cout << "Enter ID: "; cin >> id;
    cout << "Enter Name: "; cin >> name;
    cout << "Are you Buyer or Seller? "; cin >> role;

    User* user = nullptr;
    if (role == "Buyer")
        user = new Buyer(id, name);
    else if (role == "Seller")
        user = new Seller(id, name);
    else {
        cout << "Invalid role!\n";
        return 1;
    }

    user->menu();

    while (true) {
        int choice;
        cout << "\n1. Create Auction\n2. Place Bid\n3. List Active Auctions\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1 && role == "Seller") {
            string itemId;
            double price;
            int duration;
            cout << "Item ID: "; cin >> itemId;
            cout << "Min Price: "; cin >> price;
            cout << "Duration (sec): "; cin >> duration;
            lock_guard<mutex> lock(globalMutex);
            auctions[itemId] = new Auction(itemId, id, price, duration);
            cout << "Auction created for item: " << itemId << "\n";
        }
        else if (choice == 2 && role == "Buyer") {
            string itemId;
            double amount;
            cout << "Item ID: "; cin >> itemId;
            cout << "Bid Amount: "; cin >> amount;
            lock_guard<mutex> lock(globalMutex);
            if (auctions.find(itemId) != auctions.end()) {
                auctions[itemId]->placeBid(Bid(id, amount));
            }
            else {
                cout << "Auction not found.\n";
            }
        }
        else if (choice == 3) {
            listActiveAuctions();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice or action for this role.\n";
        }
    }
    lock_guard<mutex> lock(globalMutex);
    for (auto& auc : auctions) {
        delete auc.second;
    }
    delete user;

    return 0;
}


