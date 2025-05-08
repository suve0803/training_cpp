#include <iostream>
#include <sstream> 
using namespace std;
double stringToDouble(const string& str) {
    stringstream ss(str);
    double value;
    ss >> value;
    return value;
}
void triangle(int argc, char* argv[]) {
    double b, h;
    if (argc == 4) {
        b = stringToDouble(argv[2]);
        h = stringToDouble(argv[3]);
    }
    else {
        cout << "Enter base and height of the triangle: ";
        cin >> b >> h;
    }
    cout << "Area of the triangle: " << 0.5 * b * h << endl;
}
void rectangle(int argc, char* argv[]) {
    double l, w;
    if (argc == 4) {
        l = stringToDouble(argv[2]);
        w = stringToDouble(argv[3]);
    }
    else {
        cout << "Enter length and width of the rectangle: ";
        cin >> l >> w;
    }
    cout << "Area of the rectangle: " << l * w << endl;
}
void square(int argc, char* argv[]) {
    double side;
    if (argc == 3) {
        side = stringToDouble(argv[2]);
    }
    else {
        cout << "Enter the side of the square: ";
        cin >> side;
    }
    cout << "Area of the square: " << side * side << endl;
}
void circle(int argc, char* argv[]) {
    const double PI = 3.14159;
    double radius;
    if (argc == 3) {
        radius = stringToDouble(argv[2]);
    }
    else {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }
    cout << "Area of the circle: " << PI * radius * radius << endl;
}

void display() {
    int choice;
    cout << "Select a shape to calculate the area:\n";
    cout << "1. Triangle\n2. Rectangle\n3. Square\n4. Circle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        triangle(0, nullptr); 
        break;
    case 2:
        rectangle(0, nullptr); 
        break;
    case 3:
        square(0, nullptr); 
        break;
    case 4:
        circle(0, nullptr); 
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        string shape = argv[1];
        if (shape == "triangle") {
           triangle(argc, argv);
        }
        else if (shape == "rectangle") {
           rectangle(argc, argv);
        }
        else if (shape == "square") {
            square(argc, argv);
        }
        else if (shape == "circle") {
           circle(argc, argv);
        }
        else {
            cout << "Invalid shape " << endl;
            ;
        }
    }
    else {
        display(); 
    }
    return 0;
}