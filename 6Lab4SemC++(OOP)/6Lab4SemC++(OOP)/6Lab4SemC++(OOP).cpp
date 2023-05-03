#include <iostream>
#include "Container.cpp"

using namespace std;



int main() {
	int conteiner_type;
	cout << "Select type of Container 1 is char, 2 is int" << endl;
	cin >> conteiner_type;
	if (conteiner_type == 1) {
		Container<char> container;
		bool res = true;
		while (res) {
			res = container.console_interface();
		}
	}
	else if (conteiner_type == 2) {
		Container<int> container;
		bool res = true;
		while (res) {
			res = container.console_interface();
		}
	}
	

	return 0;
}
