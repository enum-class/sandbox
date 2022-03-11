#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	input.reserve(101);
	
	unsigned num = 0;
	cin >> num;

	while ( num > 0)
	{
		cin >> input;
		if (input.size() <= 10)
			cout << input << endl;
		else
			cout << input.front() << input.size() - 2 << input.back() << endl;

		--num;
	}

	return 0;
}
