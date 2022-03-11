#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <numeric>

using namespace std;

void readAndFill(vector<int>& numbers) noexcept
{
	for_each(begin(numbers), end(numbers), [](int& value) {
			cin >> value;
			});
}

void print(vector<int>& numbers) noexcept
{
	for_each(begin(numbers), end(numbers), [](const int& value) {
			cout << value << " ";
			});
	cout << endl;
}

int optimize(vector<int>& a, const vector<int>& b)
{
	int max = -1;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j <= a.size(); j++)
		{
			int tmp = inner_product(a.begin(), a.begin() + i, b.begin(), 0) +
				inner_product(a.rend() - j, a.rend() - i , b.begin() + i, 0) +
				inner_product(a.begin() + j, a.end(), b.begin() + j, 0);

			if (tmp > max)
				max = tmp;
		}
	}

	return max;
}

int fastOptimize(vector<int>& a, const vector<int>& b)
{
}

template<class InputIt1, class InputIt2, class T>
	constexpr // since C++20
T vis(InputIt1 first1, InputIt1 last1,
		InputIt2 first2, T init)
{
	while (first1 != last1) {
		cout << *first1 << "\t" << *first2 << endl;
		init = std::move(init) + *first1 * *first2; // std::move since C++20
		++first1;
		++first2;
	}
	return init;
}

int main()
{
	size_t size;
	cin >> size;

	vector<int> a(size);
	vector<int> b(size);

	readAndFill(a);
	readAndFill(b);
	
	cout << optimize(a, b);
//	int i = 0;
//	int j = 5;
//
//	vis(a.begin(), a.begin() + i, b.begin(), 0);
//	cout << "--------------------"<< endl;
//	vis(a.rend() - j, a.rend() - i , b.begin() + i, 0);
//	cout << "--------------------"<< endl;
//	vis(a.begin() + j, a.end(), b.begin() + j, 0);
//	cout << "--------------------"<< endl;
	
	return 0;
}
