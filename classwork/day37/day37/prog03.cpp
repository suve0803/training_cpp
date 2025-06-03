/*write a class for developing an stl containers like array */

#include<iostream>
#include<initializer_list>
using namespace std;
template<typename T,size_t N>
class MyArray {
	T* arr;
	size_t size;
public:
	MyArray(std::initializer_list<T>list) {
		if (list.size() > N)
			throw std::length_error("Too many arguments");
		this->arr = new T[N];
		int i = 0;
		for (const T& val : list) {
			arr[i++] = val;
		}
		//cout << N << endl;
		//size = N;
		for (;i < N;i++)
			arr[i] = T{};
	}
	void display() {
		for (int i = 0;i < N;i++)
			cout << arr[i] << endl;
	}
};
int main() {
	try{
	MyArray<int, 5> arr = { 1,2,3,4,5 };
	arr.display();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}