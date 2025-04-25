#include<iostream>
#include"stringhandling.h"
using namespace std;
int main(int argc, char*argv[])
{
	cout << argc << endl;
	cout <<"argv[0]: "<< argv[0] << endl;
	cout << "argv[1]: " << argv[1] << endl;
	cout << "argv[2]: " << argv[2] << endl;
	cout << "argv[3]: " << argv[3] << endl;
	for (int i = 0;i < argc;i++)
		cout <<"argv["<< i <<"]:" << argv[i] << endl;
	int res = atoi(argv[1]) + atoi(argv[2]);
	cout << "res:" << res << endl;
	int res = 0;
	switch (argv[1][0]) {
	case '+':
		res = atoi(argv[2]) + atoi(argv[3]);
		cout << "res:" << res << endl;
		break;
	case '-':
		res = atoi(argv[2]) - atoi(argv[3]);
		cout << "res:" << res << endl;
		break;
	default:
		break;
	}

	//stringHandling();
	//enumHandling();
	ifstatement();
	return 0;
}