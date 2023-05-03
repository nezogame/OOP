#pragma once
#include <istream>
#include "../3Lab/Ratioanl.h"
#include "PointRational.h"
#include <iostream>

PointRational::PointRational(Rational *rational) {
	ptr = rational;
}
PointRational::~PointRational() {
	if (ptr == nullptr) {
		return;
	}
	std::cout << "Rational has deleted\n";
	delete ptr;
}

Rational* PointRational::operator->() {
	return ptr;
}


std::istream& operator>>(std::istream& stream_in, PointRational& ratioanl) {
	stream_in >> (*ratioanl.ptr);
	return stream_in;
}

std::ostream& operator<<(std::ostream& stream_out, PointRational& ratioanl) {
	stream_out << (*ratioanl.ptr);
	return stream_out;
}
