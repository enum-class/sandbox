#include <iostream>
#include <utility>
#include <functional>

using namespace std;
using Result = pair<bool, double>;

//template <class T, typename ...Ts>
//using Function = std::function<T(Ts... args)>

template <class T, typename... Ts>
double bisection(T func, Ts... args) noexcept {
	return static_cast<double>(func(std::forward<Ts>(args)...));
	//return std::make_pair<true, result>;
}

double multiply(double a, double b)
{
	return a * b;
}

int main()
{
	cout << multiply(1,2) << endl;
	double result = bisection<>(multiply, 1.0, 2.0);
	cout << result << endl;
}
