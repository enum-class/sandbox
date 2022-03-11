#include <iostream>
using namespace std;

int main()
{
	unsigned weight = 0;

	cin >> weight;
	
	if ( (weight > 3) && (weight % 2 == 0) )
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
