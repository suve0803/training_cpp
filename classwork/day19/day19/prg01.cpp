#include<iostream>
using namespace std;
int main() {
	int a = 10;
	char ch = 'A';
	float f = 10.5;
	
	//void* ptr;
	int* ptr1 = nullptr;

	printf("\n Address of a=%u and it value=%d\n", &a, a);
	printf("\n Address of ch=%u and it value=%c\n", &ch, ch);
	printf("\n Address of f=%u and it value=%f\n", &f, f);
	printf("\n Address of ptr=%u and it value=%u\n", &ptr1, ptr1);
	a = 10;
	ptr1 = &a;

	printf("\n Address of ptr=%u and it value=%u\n", &ptr1, ptr1);

	printf("\nptr1 is pointing to=%u", ptr1);
	printf("\n%u is having a value stored as=%d\n", ptr1.*ptr1);
	/*cout << "Address of a= " << (unsigned long int) & a << " and it value= " << a<<endl;
	cout << "Address of a= " << (unsigned long int) & ch << " and it value= " << ch << endl;
	cout << "Address of a= " << (unsigned long int) & f << " and it value= " << f << endl;
	cout << "Address of a= " << & ptr << " and it value= " << ptr << endl;
*/
}