
#include <iostream> 
#include "PointRational.h" 
using namespace std;
Rational a2(10, 4);
Rational b2(a2);
Rational a;
Rational b;
Rational k;
PointRational mali (new Rational());
float type_cast;


int main() {
	bool result=true;
	int action;


	do {
			std::cout << "Choose your action (from 1 to 3).\n"
				"1 is enter two ratioanl number\n"
				"2 is cast from rational to float\n"
				"3 is add 2 numbers\n"
				"4 is subtract 2 numbers\n"
				"5 is multiply 2 numbers\n"
				"6 is divide 2 numbers\n"
				"7 is print numerator and Denuminator for two ratioanl number  \n"
				"8 is pseudo-variables implementation\n"
				"9 is smart pointer implementation\n"
				"0 if you want to finish the program " << endl;

			cin >> action;
			cout << endl;
			switch (action) {
			case 1:
				
				cin >> mali;
				cin >> a;
				cin >> b;
				break;
			case 2:
				type_cast = a;
				cout << "Cast from rational to float: " << type_cast << endl;
				break;
			case 3:
				k = a + b;
				cout << "Summa result of a + b:" << k << endl;
				k = a - b;
				break;
			case 4:
				k = a - b;
				cout << "Difference result of a - b:" << k << endl;
				break;
			case 5:
				k = a * b;
				cout << "Multiplication result of a + b:" << k << endl;
				break;
			case 6:
				k = a / b;
				cout << "Division result of a - b:" << k << endl;
				break;
			case 7:

				cout << "Numerator for first ratioanl number: " << a[0] << endl;
				cout << "Denuminator for first ratioanl number: " << a[1] << endl << endl;

				cout << "Numerator for second ratioanl number: " << b[0] << endl;
				cout << "Denuminator for second ratioanl number: " << b[1] << endl << endl;
				break;
			case 8: {
				Rational first(5, 10);
				first(0) = 30;
				first(1) = 60;
				cout << "First - " << first << endl; }
				break;
			case 9: {
				PointRational second(new Rational());
				second->set_numerator(200);
				second->set_denuminator(300);
				cout << "Second - " << second << endl;
			}

				break;
			case 0:
				std::cout << "Thanks for using, bye bye\n";
				result = false;
				return result;
				break;
			default:
				cout << "Wrong number!!!";
			}
			cout << "\n\n";
	} while (result);
}
