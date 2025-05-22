#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int iid;
    string iname;
    float iprice;
    int iquantity;

public:

    void setiid(int i) {
        iid = i;
    }
    void setiname(string n) {
        iname = n;
    }
    void setiprice(float p) {
        iprice = p;
    }
    void setiquantity(int q) {
        iquantity = q;
    }

    void display() {
        cout << "ID: " << iid << ", Name: " << iname << ", Price: " << iprice
            << ", Quantity: " << iquantity << endl;
    }
    int getiid() { 
        return iid; 
    }
    string getiname() { 
        return iname; 
    }
    double getiprice() { 
        return iprice; 
    }
    int getiquantity() { 
        return iquantity; 
    }
    void reduceiquantity(int qty) { 
        iquantity =iquantity- qty; 
    }
};

class RetailShop {
private:
    Item item[100]; 
    int iCount;       

public:

    RetailShop() { 
        iCount = 0; 
    }
    void add() {
        int iid, iquantity;
        string iname;
        double iprice;

        cout << "Enter item ID: ";
        cin >> iid;
        cout << "Enter item name: ";
        cin >> iname;
        cout << "Enter item price: ";
        cin >> iprice;
        cout << "Enter item quantity: ";
        cin >> iquantity;
        item[iCount].setiid(iid);
        item[iCount].setiname(iname);
        item[iCount].setiprice(iprice);
        item[iCount].setiquantity(iquantity);
        iCount++;
        cout << "Item added successfully" << endl;
    }

    void display() {
        
        for (int i = 0; i < iCount; i++) {
            item[i].display();
        }
    }
    void search() {
        int id;
        cout << "Enter item ID to search: ";
        cin >> id;

        for (int i = 0; i < iCount; i++) {
            if (item[i].getiid() == id) {
                cout << "Item found:";
                item[i].display();
                return;
            }
        }
    }

    void sell() {
        int id, quantity;
        cout << "Enter item ID to sell: ";
        cin >> id;
        cout << "Enter quantity: ";
        cin >> quantity;

        for (int i = 0; i < iCount; i++) {
            if (item[i].getiid() == id) {
                if (item[i].getiquantity() >= quantity) {
                    double totalPrice = item[i].getiprice() * quantity;
                    item[i].reduceiquantity(quantity);
                    cout << " Total price: " << totalPrice << endl;
                }
                else {
                    cout << "Insufficient stock"<<endl;
                }
                return;
            }
        }
        cout << "Item not found"<<endl;
    }
};

int main() {
    RetailShop shop;
    int choice;

    do {
        cout << "1. Add Item "<<endl;
        cout << "2. Display " << endl;
        cout << "3. Search" << endl;
        cout << "4. Sell" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            shop.add();
            break;
        case 2:
            shop.display();
            break;
        case 3:
            shop.search();
            break;
        case 4:
            shop.sell();
            break;
        case 5:
            cout << "Exiting" <<endl;
            break;
        default:
            cout << "Invalid choice"<<endl;
        }
    } while (choice != 5);

    return 0;
}