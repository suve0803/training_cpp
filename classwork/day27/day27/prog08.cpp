/*create a class array which has
1.get Biggest of arr elements
2.get arr sorted in ascending order
3.get arr sorted in decending order*/
#include<iostream>
using namespace std;
class Array {
private:
	int arr[50];
	int size;
public:
	void init() {
		cout << "Enter the size of the array: ";
		cin >> size;

		cout << "Enter " << size << " elements:"<<endl;
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
	}
	void largest() {
		int max = arr[0];
		for (int i = 1;i < size;i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
	cout<< max<<endl;
	}
	void ascending() {
		for (int i = 0;i < size ;i++) {
			int min = i;
			for (int j = i + 1;j < size;j++) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			}
			int t = arr[i];
			arr[i] = arr[min];
			arr[min] = t;
		}
	}
	void descending() {
		for (int i = 0;i < size-1;i++) {
			int max = i;
				for (int j = i + 1;j < size;j++) {
					if (arr[j] > arr[max]) {
						max = j;
					}
				}
				int t = arr[i];
				arr[i] = arr[max];
				arr[max] = t;
			}
		}
		void disp() {
			for (int i = 0;i < size;i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	
};
int main() {
	Array a;
	a.init();
	cout << "Array: " << endl;
	a.disp();

	cout << "Largest Element: " << endl;
	a.largest();

	a.ascending();
	cout << "Array in Ascending Order: ";
	a.disp();

	a.descending();
	cout << "Array in Descending Order: ";
	a.disp();

	return 0;
}