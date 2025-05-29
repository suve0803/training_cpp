#include<iostream>
using namespace std;
class Animal {
protected:
	string sound;
public:
	Animal() :sound("animal sound") {}
	void eat() {
		cout << "Eat" ;
	}
	void walk() {
		cout << "Walk" ;
	}
	void makeasound() {
		cout << "Make a sound" ;
	}
	void soundlike() {
		cout << "Animal sound";
	}
};
class cat :public Animal {
public:
	void dispcat() {
		cout << "Cat" ;
	}
	void soundlike() {
		cout << "Meow!";
	}
	
};
class dog :public Animal {
public:
	void dispdog() {
		cout << "Dog" ;
	}
	void soundlike() {
		cout << "Bow Bow!";
	}

};
int main() {
	Animal* bcPtr = nullptr;

	cat c;
	dog d;

	c.dispcat();
	c.eat();
	c.walk();
	c.makeasound();
	c.soundlike();

	d.dispdog();
	d.eat();
	d.walk();
	d.makeasound();
	d.soundlike();

	bcPtr = &c;

	//bcPtr->displayCat();

	bcPtr->eat();
	bcPtr->walk();
	bcPtr->makeasound();
	bcPtr->soundlike();

	bcPtr = &d;

	bcPtr->eat();
	bcPtr->walk();
	bcPtr->makeasound();
	bcPtr->soundlike();
	
}