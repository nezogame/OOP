#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "BitwiseLogicalOperations.h"

template <typename T>
class Container
{
private:
	std::vector<T> first_vec;
	std::vector<T> second_vec;
public:

	Container() {} // default constructor

	std::vector<T> get_first_vec() const;

	std::vector<T> get_second_vec() const;

	void set_first_vec(const std::vector<T> &);

	void set_second_vec(const std::vector<T> &);


	void print_vectors();

	void add_element();

	void remove_elemnt(int i, int index);

	bool validate_size();

	bool validate_vectors_size();

	bool console_interface();
};

