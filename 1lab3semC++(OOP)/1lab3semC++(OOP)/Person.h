#pragma once
#include <string.h>;
#include <string>;
using namespace std;
class Person
{
private:
	string name;
	string surname;
	int age;
public:
	Person() {
		setName("Petro");
		setSurname("Revo");
		setAge(18);
	}
	Person(string name, string surname, int age) {
		setName(name);
		setSurname(surname);
		setAge(age);
	}
	//Geter
	string getName() {
		return name;
	}
	//Setter
	void setName(string n) {
		name = n;
	}

	//Geter
	string getSurname() {
		return surname;
	}
	//Setter
	void setSurname(string surN) {
		surname = surN;
	}

	//Geter
	int getAge () {
		return age;
	}
	//Setter
	void setAge(int n) {
		if (n > 0) {
			age = n;
		}
		else {
			age = 1;
		}
	}
	virtual string to_String() {
		string s = "Name :" + getName() + ", Surname: " + getSurname() + ", Age: " + to_string(getAge()) + "\n";
		return s;
	}
};

