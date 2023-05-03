#pragma once
#include <iostream>
#include "Ratioanl.h"

using namespace std;
Rational::Rational() : numerator(0), denuminator(1) {};

Rational::Rational(int num, int denum) {
	if (num < 0 && denum < 0) {
		num = -num;
		denum = -denum;
	}
	numerator = num;
	denuminator = denum;
	reduce();
}
Rational::Rational(Rational& rat_num) {
	numerator = rat_num.numerator;
	denuminator = rat_num.denuminator;
}

void Rational::reduce() {
	int min, max;
	numerator > denuminator ? (min = abs(denuminator), max = abs(numerator)) : (min = abs(numerator), max = abs(denuminator));
	for (int delimeter = 1; delimeter <= min / 2; delimeter++) {
		if (min % delimeter == 0 && max % (min / delimeter) == 0) {
			numerator /= (min / delimeter);
			denuminator /= (min / delimeter);
			return;
		}
	}
}


int& Rational::operator [] (int index) {
	if (index == 0) {
		return numerator;
	}
	else if (index == 1) {
		return denuminator;
	}
	else {
		cout << "Wrong index\n";
	}
}


Rational Rational::operator=(const Rational& ratioanl) {
	numerator = ratioanl.numerator;
	denuminator = ratioanl.denuminator;
	return *this;
}
Rational::operator float() const {
	return static_cast<float>(numerator) / denuminator;
}
istream& operator>>(istream& stream_in, Rational& ratioanl) {
	cout << "Enter rational value (a/b): ";
	stream_in >> ratioanl.numerator;
	stream_in.ignore();
	stream_in >> ratioanl.denuminator;
	if (ratioanl.numerator < 0 && ratioanl.denuminator < 0) {
		ratioanl.numerator = -ratioanl.numerator;
		ratioanl.denuminator = -ratioanl.denuminator;
	}
	ratioanl.reduce();
	cout << endl;
	return stream_in;
}

ostream& operator<<(ostream& stream_out, Rational& ratioanl) {
	stream_out << "Rational number: " << ratioanl.numerator << "/" << ratioanl.denuminator << endl;
	return stream_out;
}
Rational Rational::operator+(const Rational& ratioanl) const {
	int sum_num, denum;
	sum_num = (numerator * ratioanl.denuminator) + (ratioanl.numerator * denuminator);
	denum = denuminator * ratioanl.denuminator;
	Rational sum(sum_num, denum);
	return sum;
}
Rational Rational::operator-(const Rational& ratioanl) const {
	int dif_num, denum;
	dif_num = (numerator * ratioanl.denuminator) - (ratioanl.numerator * denuminator);
	denum = denuminator * ratioanl.denuminator;
	Rational difference(dif_num, denum);
	return difference;
}
Rational  Rational::operator*(const Rational& ratioanl) const {
	int mult_num, denum;
	mult_num = numerator * ratioanl.numerator;
	denum = denuminator * ratioanl.denuminator;
	Rational multiplication(mult_num, denum);
	return multiplication;
}
Rational  Rational::operator/(const Rational& ratioanl) const {
	int div_num, denum;
	div_num = numerator * ratioanl.denuminator;
	denum = denuminator * ratioanl.numerator;
	Rational division(div_num, denum);
	return division;
}

void Rational::set_numerator(int num){
	(*this)[0] = num;
}
void Rational::set_denuminator(int denum){
	(*this)[1] = denum;
}
int& Rational::operator () (int index) {
	if (index == 0) {
		return numerator;
	}
	else if (index == 1) {
		return denuminator;
	}
	else {
		cout << "Wrong index\n";
	}
}