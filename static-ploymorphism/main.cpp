#include <iostream>

#include "BigClass.h"

using namespace std;

int main()
{
	BigClass a(1);
	BigClass b(2);
	BigClass c(3);
	BigClass d(3);
	BigClass e;

	e = a + b + c + d;
	cout << e.value << endl;
	return 0;
}
