#pragma once

#include <istream>

class Rational
{
	int numerator;
	int denuminator;

	friend std::istream& operator>>(std::istream&, Rational&);
	friend std::ostream& operator<<(std::ostream&, Rational&);
	void reduce();

public:
	Rational();
	Rational(int, int);
	Rational(Rational&);


	int& operator[](int);
	Rational operator = (const Rational&);
	operator float() const;
	Rational operator*(const Rational&) const;
	Rational operator+(const Rational&) const;
	Rational operator-(const Rational&) const;
	Rational operator/(const Rational&) const;

};



