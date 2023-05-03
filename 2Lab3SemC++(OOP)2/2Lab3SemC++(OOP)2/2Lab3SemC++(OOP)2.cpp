
#include <iostream> 
#include "Rational.h" 
using namespace std;
int main() {

	Rational a2(10, 4);
	Rational b2(a2);
	Rational a;
	Rational b;
	Rational k;
	float type_cast;



	cout << "Enter first ratioanl number:\n";
	cin >> a;
	cout << "Your first  " << a;
	cout << "\nEnter second ratioanl number:\n";
	cin >> b;
	cout << "Your second  " << b;
	k = a + b;
	cout << "-----------------------------------------\n";
	type_cast = a;
	cout << "Cast from rational to float: " << type_cast << endl;

	cout << "Numerator for first ratioanl number: " << a[0] << endl;
	cout << "Denuminator for first ratioanl number: " << a[1] << endl << endl;

	cout << "Numerator for second ratioanl number: " << b[0] << endl;
	cout << "Denuminator for second ratioanl number: " << b[1] << endl << endl;


	cout << "Summa result of a + b:" << k << endl;
	k = a - b;
	cout << "Difference result of a - b:" << k << endl;
	k = a * b;
	cout << "Multiplication result of a + b:" << k << endl;
	k = a / b;
	cout << "Division result of a - b:" << k << endl;
	return 0;
}
