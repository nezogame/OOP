#pragma once
#include "Person.h"
using namespace std;
class Copywriter: Person
{
private:
    string nickName;
    int booksPublished;
public:

	Copywriter() :Person() 
	{
		setNickName("<Blank>");
		setBooksPublished(0);
    }
    Copywriter(string name, string surname, int age, string nickName, int booksPublished) :Person(name, surname, age)
	{
		setNickName(nickName);
		setBooksPublished(booksPublished);
    }
	//Geter
	string getNickName() {
		return nickName;
	}
	//Setter
	void setNickName(string n) {
		nickName = n;
	}

	//Geter
	int getBooksPublished() {
		return booksPublished;
	}
	//Setter
	void setBooksPublished(int books) {
		booksPublished = books;
	}
	string to_String() override {
		string rank;
		if (getBooksPublished() >= 50) {
			rank = "Professor\n";
		}
		else if (getBooksPublished() < 50 && getBooksPublished() >= 20)
		{
			rank = "Average\n";
		}
		else if (getBooksPublished() < 20 && getBooksPublished() >= 5) {
			rank = "Beginer\n";
		}
		else {
			rank = "Elementary\n";
		}
		string s = Person::to_String() + "Autor nickname: " + getNickName() + ", Number of published books are: "+ to_string(getBooksPublished()) + ", Autor rank is: " + rank+"\n";
		return s;
	}

};

