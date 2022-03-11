#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v{1,2,3,4,1,2,3};

	auto result = find(begin(v), end(v), 2);
	cout << result - begin(v) << endl;

	result = find(begin(v), end(v), 3);
	cout << result - begin(v) << endl;

	return 0;
}
