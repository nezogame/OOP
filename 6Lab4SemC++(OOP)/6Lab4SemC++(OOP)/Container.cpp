#include "Container.h"

template <typename T>
std::vector<T> Container<T>::get_first_vec() const {
	return first_vec;
}

template <typename T>
std::vector<T> Container<T>::get_second_vec() const {
	return second_vec;
}

template <typename T>
void Container<T>::set_first_vec(const std::vector<T>& vector) {
	first_vec = vector;
}

template <typename T>
void Container<T>::set_second_vec(const std::vector<T>& vector) {
	second_vec = vector;
}

template <typename T>
void Container<T>::print_vectors() {
	std::cout << "Vector 1: ";
	if (first_vec.empty()) {
		std::cout << "is empty";
	}
	for (const T& element : first_vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::cout << "Vector 2: ";
	if (second_vec.empty()) {
		std::cout << "is empty";
	}
	for (const T& element : second_vec) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void Container<T>::add_element() {
	T first_element, second_element;
	std::cout << "\nEnter first element: ";
	std::cin >> first_element;
	std::cout << "\nEnter second element: ";
	std::cin >> second_element;
	first_vec.push_back(first_element);
	second_vec.push_back(second_element);

}

template <typename T>
void Container<T>::remove_elemnt(int i, int index) {

	if (i == 1) {
		if (first_vec.empty()) {
			std::cout << "Vector alredy empty";
			return;
		}
		first_vec.erase(first_vec.begin() + index);
	}
	else if (i == 2) {
		if (second_vec.empty()) {
			std::cout << "Vector alredy empty";
			return;
		}
		second_vec.erase(second_vec.begin() + index);
	}
	else {
		std::cout << "You enter incorect index of vector, it's only 1 or 2!!!";
	}
}

template <typename T>
bool Container<T>::validate_size() {
	return first_vec.size() == second_vec.size();
}

template <typename T>
bool Container<T>::validate_vectors_size() {
	if (!(validate_size())) {
		std::cout << "vector size not the same" << std::endl;
		print_vectors();
		return false;
	}
	return true;
}


template <typename T>
bool Container<T>::console_interface() {
	int action, vector_number, index;
	T element;
	std::cout << "Chose action:\n";
	std::cout << "1) Add element\n";
	std::cout << "2) Remove element by index\n";
	std::cout << "3) Print all vectors\n";
	std::cout << "4) Invoke bitwise AND\n";
	std::cout << "5) Invoke bitwise OR\n";
	std::cout << "6) Invoke bitwise XOR\n";
	std::cout << "0) Exit out\n";
	std::cin >> action;
	if (action == 1) {

		add_element();
	}
	else if (action == 2) {
		std::cout << "\nEnter vector(1 or 2) form wich you want to delete: ";
		std::cin >> vector_number;
		std::cout << "\nEnter index: ";
		std::cin >> index;
		remove_elemnt(vector_number, index);
	}
	else if (action == 3) {
		print_vectors();
	}
	else if (action == 4) {
		if (!validate_vectors_size()) {
			return true;
		}
		std::vector<T> first_vec = get_first_vec();
		std::vector<T> second_vec = get_second_vec();
		// AND vector 
		std::vector<T> AND_vector(get_first_vec().size());
		std::transform(first_vec.begin(), first_vec.end(),
			second_vec.begin(), AND_vector.begin(), BitwiseLogicalOperations::bitwise_AND<T>);
		std::cout << "Vector AND result: ";
		for (T element : AND_vector) {
			std::cout << element << " ";
		}
		std::cout << std::endl;

	}
	else if (action == 5) {
		if (!validate_vectors_size()) {
			return true;
		}
		std::vector<T> first_vec = get_first_vec();
		std::vector<T> second_vec = get_second_vec();
		// OR vector 
		std::vector<T> OR_vector(get_first_vec().size());
		std::transform(first_vec.begin(), first_vec.end(),
			second_vec.begin(), OR_vector.begin(), BitwiseLogicalOperations::bitwise_OR<T>);
		std::cout << "Vector OR result: ";
		for (T element : OR_vector) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
	else if (action == 6) {
		if (!validate_vectors_size()) {
			return  true;
		}
		std::vector<T> first_vec = get_first_vec();
		std::vector<T> second_vec = get_second_vec();
		// XOR vector 
		std::vector<T> XOR_vector(get_first_vec().size());
		std::transform(first_vec.begin(), first_vec.end(),
			second_vec.begin(), XOR_vector.begin(), BitwiseLogicalOperations::bitwise_XOR<T>);
		std::cout << "Char vector XOR result: ";
		for (T element : XOR_vector) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
	else if (action == 0) {
		return false;
	}
	else {
		std::cout << "Wrong action!\n";
	}
	return true;
}