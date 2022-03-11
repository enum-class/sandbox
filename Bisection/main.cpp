/**
 * Find where the function become zero in [a, b]
 * The simplest root-finding algorithm is the bisection method.
 * Let f be a continuous function, for which one knows an interval [a, b]
 * such that f(a) and f(b) have opposite signs (a bracket).
 * Let c = (a +b)/2 be the middle of the interval (the midpoint or the point that
 * bisects the interval).
 * Then either f(a) and f(c), or f(c) and f(b) have opposite signs,
 * and one has divided by two the size of the interval.
 * Although the bisection method is robust,
 * It gains one and only one bit of accuracy with each iteration.
 * Other methods, under appropriate conditions, can gain accuracy faster. 
 */

#include <iostream>
#include <algorithm>
#include <limits>
#include <exception>
#include <functional>

using namespace std;

double bisection_i(double start, double end, double (*function)(double))
{
	if (start > end)
		swap(start, end);
	
	if (end - start < 0.0001)
		throw std::runtime_error("Not found");

	double f_start = (*function)(start);
	double f_end = (*function)(end);

	if (f_start * f_end > 0)
		throw std::runtime_error("Not found");
	
	double middle = (start + end) / 2;
	double f_middle = (*function)(middle);

	if (f_middle == 0)
		return middle;

	if (f_middle * f_start < 0)
		return bisection_i(start, middle, (*function));
	else
		return bisection_i(middle, end, (*function));
}

double bisection_ii(double start, double end, function<double(double)> function)
{
	if (start > end)
		swap(start, end);
	
	if (end - start < 0.0001)
		throw std::runtime_error("Not found");

	double f_start = function(start);
	double f_end = function(end);

	if (f_start * f_end > 0)
		throw std::runtime_error("Not found");
	
	double middle = (start + end) / 2;
	double f_middle = function(middle);

	if (f_middle == 0)
		return middle;

	if (f_middle * f_start < 0)
		return bisection_ii(start, middle, function);
	else
		return bisection_ii(middle, end, function);
}

double line(double x)
{
	return x + 2;
}

struct Line
{
	double operator()(double x) const
	{
		return line(x);
	}
};

int main()
{
	cout << bisection_i(-5, 1, line) << endl;
	cout << bisection_ii(-5, 1, line) << endl;
	cout << bisection_ii(-5, 1, Line()) << endl;
	cout << bisection_ii(-5, 1, [](double x) {return line(x);}) << endl;
	return 0;
}
