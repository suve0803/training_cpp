/*find a name of a cricketer in a list of cricketers in a 2D array using Binary search*/
#include<iostream>
using namespace std;
int search(string cricketer, int row, int col,string target) {
	int start = 0;
	int end = (row*col)-1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int i = mid / col;
		int j = mid % col;
		if (cricketer[i][j] == target) {
			return 1;
		}
		else if (cricketer[i][j] < target) {
			end = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return 1;
}
int main() {
	int row = 4;
	int col = 4;
	for (int i = 0;i < row;i++) {

	}

}