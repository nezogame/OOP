

#include <iostream>
#include <string.h>
#include <string>
#include "Copywriter.h"
#include "Function.h"
#include <cstdlib>	
using namespace std;

int main()
{
	printHW();
	Person personFirst{ "Ivan", "Semypalov", 28 };
	Copywriter copywriterFirst{ personFirst.getName(), personFirst.getSurname(), personFirst.getAge(), "Semerochka", 67 };

	Person* personSecond = new Person();
	Copywriter* copywritSecond = new Copywriter();

	cout << personFirst.to_String();
	cout << copywriterFirst.to_String();
	cout << personSecond->to_String();
	cout << copywritSecond->to_String();
	delete personSecond;
	delete copywritSecond;
	system("pause");
}

