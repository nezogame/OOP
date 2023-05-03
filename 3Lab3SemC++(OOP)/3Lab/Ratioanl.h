#pragma once

#include <istream>

class Rational
{
	int numerator;
	int denuminator;

	friend std::istream& operator>>(std::istream&, Rational&);
	friend std::ostream& operator<<(std::ostream&, Rational&);

public:
	void reduce();
	Rational();
	Rational(int, int);
	Rational(Rational&);

	void set_numerator(int);
	void set_denuminator(int);

	int& operator[](int);
	int& operator()(int);
	Rational operator = (const Rational&);
	operator float() const;
	Rational operator*(const Rational&) const;
	Rational operator+(const Rational&) const;
	Rational operator-(const Rational&) const;
	Rational operator/(const Rational&) const;

};




