#include <iostream>
using namespace std;

int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;

    while (binary > 0) {
        int lastDigit = binary % 10; 
        decimal += lastDigit * base; 
        base *= 2;                   
        binary /= 10;                
    }

    return decimal;
}

int decimalToBinary(int decimal) {
    int binary = 0, base = 1;

    while (decimal > 0) {
        int remainder = decimal % 2; 
        binary += remainder * base; 
        base *= 10;                 
        decimal /= 2;               
    }

    return binary;
}

int octalToDecimal(int octal) {
    int decimal = 0, base = 1;

    while (octal > 0) {
        int lastDigit = octal % 10; 
        decimal += lastDigit * base; 
        base *= 8;                   
        octal /= 10;                 
    }

    return decimal;
}

int decimalToOctal(int decimal) {
    int octal = 0, base = 1;

    while (decimal > 0) {
        int remainder = decimal % 8; 
        octal += remainder * base;  
        base *= 10;                 
        decimal /= 8;               
    }

    return octal;
}

int main() {
    int choice, number;

    cout << "Conversion Menu:\n";
    cout << "1. Binary to Decimal\n";
    cout << "2. Decimal to Binary\n";
    cout << "3. Octal to Decimal\n";
    cout << "4. Decimal to Octal\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << "Enter the number: ";
    cin >> number;

    switch (choice) {
    case 1:
        cout << "Binary to Decimal: " << binaryToDecimal(number) << endl;
        break;
    case 2:
        cout << "Decimal to Binary: " << decimalToBinary(number) << endl;
        break;
    case 3:
        cout << "Octal to Decimal: " << octalToDecimal(number) << endl;
        break;
    case 4:
        cout << "Decimal to Octal: " << decimalToOctal(number) << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}