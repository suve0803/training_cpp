#ifndef __RETAIL__
#define __RETAIL__

class Item {
private:
    int iid;
    char iname[30];
    float iprice;
    int iquantity;

public:

    void setDetails(int iId, char* iName, double iPrice, int iQuantity) {
        iid = iId;
        iname = iName;
        iprice = Price;
        quantity = itemQuantity;
    }
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price
            << ", Quantity: " << quantity << endl;
    }
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }
    int getQuantity() {
        return quantity;
    }
    void reduceQuantity(int qty) {
        quantity = quantity - qty;
    }
};
#endif


/*inventory[iCount].setDetails(id, name, price, quantity);
        iCount++;*/