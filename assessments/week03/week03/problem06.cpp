/*Problem Statement 6
You are given an array arr[] of size N containing positive integers. Your task is to reverse every sub-array of size K.

If the number of elements left at the end is less than K, reverse all of them as is.*/


#include <iostream>
#define SIZE 200
using namespace std;

void reverse(int arr[], int N, int K) {
    for (int i = 0; i < N; i += K) {
        int start = i;
        int end = min(i + K - 1, N - 1);

        while (start < end) {
         
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}

int main() {
    int n;
    cin >> n;  

    int arr[SIZE];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    int K;
    cin >> K;  

    reverse(arr, n, K);  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  
    }
    cout << endl;

    return 0;
}

/*OUTPUT
6
1 2 3 4 5 6
3
3 2 1 6 5 4

10
1 2 3 4 5 6 7 8 9 10
3
3 2 1 6 5 4 9 8 7 10

6
1 2 1 5 5 6
3
1 2 1 6 5 5


*/