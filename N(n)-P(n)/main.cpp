#include <iostream>
#include <vector>

using namespace std;

constexpr int NK(int n, int k)
{
	return k == 1 ? n : (n/k) * NK(n-1,k-1);
}

typedef vector<vector<int>> Result;

void combination(int n, int k, Result& result)
{
	if (n < k)
		return;

	if (k == 1)
	{
		for (int i = n; i > 0; i--)
		{
			vector<int> tmp = {i};
			result.push_back(tmp);
		}

		return;
	}

	Result sub_result;
	combination(n - 1, k - 1, sub_result);
	for (vector<int>& element : sub_result)
	{
		element.push_back(n);
		result.push_back(element);
	}

	combination(n - 1, k, result);
}

int main()
{
	Result result;
	combination(4, 2, result);

	for (vector<int>& element: result)
	{
		cout << " {  ";
		for (int& data : element)
			cout << data << " ";

		cout << " } \n";
	}

	return 0;
}
