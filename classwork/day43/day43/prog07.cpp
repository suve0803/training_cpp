#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;
int main() {
    vector<int> cart = { 199, 599, 999, 1, 0, 75, 1200 };

    cout << "Cart Prices in Reverse: ";
    for (vector<int>::reverse_iterator rit = cart.rbegin(); rit != cart.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
    for (vector<int>::iterator it = cart.begin(); it != cart.end(); ++it) {
        if (*it > 500) *it -= 50;
    }
    cout << "Cart after Discount: ";
    for (int price : cart) cout << price << " ";
    cout <<endl;
    int free_items = 0;
    for (vector<int>::const_iterator cit = cart.cbegin(); cit != cart.cend(); ++cit) {
        if (*cit < 1) ++free_items;
    }
    cout << "Number of Free Items: " << free_items << "\n";
    std::sort(cart.begin(), cart.end());
    int total = std::accumulate(cart.begin(), cart.end(), 0);

    std::cout << "Sorted Cart: ";
    for (int p : cart) std::cout << p << " ";
    std::cout << "\nTotal Checkout Amount: " << total << "\n";

    return 0;
}