/*Movie Rating System*/
#include<iostream>
#include<cstring>
using namespace std;

class Movie {
private:
	char title[50];
	char genre[20];
	float rating;
public:
	void settitle(char* t) {
		strcpy(title, t);
	}
	char* gettitle() {
		return title;
	}
	void setgenre(char* g) {
		strcpy(genre, g);
	}
	char* getgenre() {
		return genre;
	}
	void setrating(float r) {
		rating = r;
	}
	float getrating() {
		return rating;
	}
	void display() {
		cout << "Title: " << title << endl;
		cout << "Genre: " << genre << endl;
		cout << "Rating: " << rating << endl;
		if ((rating >= 8.0) && (rating <= 10.0)) {
			cout << "Result: Hit";
		}
		else if ((rating >= 5.0) && (rating < 8.0)) {
			cout << "Result: Average";
		}
		else if (rating < 5.0)  {
			cout << "Result: Flop";
		}
		else {
			cout << "Invalid input";
		}

	}
	/*float result() {
		float rating=0.0;

		if ((rating >= 10.0) && (rating <= 8.0)) {
			cout << "Result: Hit";
		}
		else if ((rating < 8.0) && (rating >= 5.0)) {
			cout << "Result: Average";
		}
		else if ((rating < 5.0) && (rating > 0.0)) {
			cout << "Result: Flop";
		}
		else {
			cout << "Invalid input";
		}
	}*/
};

int main() {
	char t[] = "movie";
	char g[] = "horror";
	float r = 8.5;

	Movie M;
	M.settitle(t);
	M.setgenre(g);
	M.setrating(r);
	M.display();
	return 0;

}