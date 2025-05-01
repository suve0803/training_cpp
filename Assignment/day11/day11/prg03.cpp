#include <iostream>
using namespace std;

void leaders(int arr[], int n) {
    int* leaders = new int[n];
    int count = 0;  

    int right = arr[n - 1];
    leaders [count++] = right;  

    
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > right) {  
            leaders[count++] = arr[i];  
            right = arr[i];  
        }
    }

    
    for (int i = count - 1; i >= 0; i--) {
        cout << leaders[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;  

     int* arr = new int[n];  

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    leaders(arr, n); 
    return 0;
}
