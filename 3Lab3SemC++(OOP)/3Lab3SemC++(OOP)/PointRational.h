#pragma once
#include <istream>
#include "../3Lab/Ratioanl.h"

class PointRational {
	Rational* ptr;
public:
	PointRational(Rational* rational);
	~PointRational();

	Rational* operator->();
	friend std::istream& operator>>(std::istream&, PointRational&);
	friend std::ostream& operator<<(std::ostream&, PointRational&);
};