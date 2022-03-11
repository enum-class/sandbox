#include <iostream>
#include <unordered_map>
#include <math.h>

using namespace std;

typedef unordered_map<unsigned int, unsigned int> map_type;

unsigned int func(unsigned int n, unsigned int k, map_type& mem)
{
	if (mem.find(n) != mem.end())
		return mem[n];

	unsigned int result = 0;

	if (n == 1)
	{
		result = 1;
	}
	else
	{
		result += pow(n, k);

		for (unsigned int i = 1; i < n; i++)
		{
			unsigned int tmp;
			tmp = func(n-i, k, mem);
			result += pow(i, k) * tmp;
		}
	}

	mem[n] = result;
	return result;
}

int main()
{
	unsigned int n = 100;
	unsigned int k = 2;
	cin >> n >> k;
	map_type mem;
	unsigned int result;
	result = func(n, k, mem);
	
	cout << result % 1000000007 << endl;
	return 0;
}
