#include <iostream>
#include "Matrix.h"
#include <array>
#include <algorithm>

using namespace std;

int main()
{
	Matrix<double, 3, 3> m1;
	Matrix<double, 3, 3> m2;
	Matrix<double, 3, 3> m3;
	
	m3 = m2 * m1;
	
	array<int, 3> a = {1, 2, 3};
	array<int, 3> b;
	transform(a.begin(), a.end(), b.begin(), [](const auto& i) { return i * 3; });

	for_each(b.begin(), b.end(), [](const auto& i) { cout << i << endl; });
	return 0;
}
