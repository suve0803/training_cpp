// cppProj01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<addition.h>
#include<subraction.h>
#include<multiplication.h>
#include<division.h>
using namespace std;
int main()
{
    int v1, v2;
    int ret = 0;
    cout << "Enter the values of val1 & val2 :"<<endl;
    cin >> v1 >> v2;
    ret=addition(v1,v2);
    cout << "\nAddition of" << v1 << " and " << v2 << " is " << ret << endl;
    ret = subraction(v1, v2);
    cout << "\nAddition of" << v1 << " and " << v2 << " is " << ret << endl;
    ret = multiplication(v1, v2);
    cout << "\nAddition of" << v1 << " and " << v2 << " is " << ret << endl;
    ret = division(v1, v2);
    cout << "\nDivision of" << v1 << " and " << v2 << " is " << ret << endl;
    return 0;
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
