#include <iostream>
#include <string>

using namespace std;

/**
 *
 * However, there is a drawback with this version: Static constant members are lvalues. So, if you have a declaration such as
 *
 * void foo(int const&);
 *
 * and you pass it the result of a metaprogram:
 *
 * foo(Fact<7>::fact);
 *
 * a compiler must pass the address of Pow3<7>::value, and that forces the compiler to instantiate and allocate the definition for the static member.
 * As a result, the computation is no longer limited to a pure “compile-time” effect
 *
 */
template <int N>
struct FactV1
{
	static const int fact = N * FactV1<N-1>::fact;
};

template <>
struct FactV1<1>
{
	static const int fact = 1;
};

template <int N>
struct FactV2
{
	enum
	{
		fact = N * FactV2<N-1>::fact
	};
};

template <>
struct FactV2<1>
{
	enum
	{
		fact = 1
	};
};

template <typename T>
struct removeConst
{
	typedef T type;
};

template <typename T>
struct removeConst<const T>
{
	typedef T type;
};

/// Equal to void_t
template <typename ...>
using try_to_instantiate = void;

template <typename T, typename = void>
struct is_incrementable : std::false_type
{
};

template <typename T>
struct is_incrementable <T, try_to_instantiate<decltype(++std::declval<T&>())>>: std::true_type
{
};

template <typename T, typename U, typename = void>
struct myis_assignable : std::false_type
{
};

template <typename T, typename U>
struct myis_assignable <T, U, try_to_instantiate<decltype(std::declval<T&>() = std::declval<U&>())>> : std::true_type
{
};

int main()
{
	cout << FactV1<4>::fact << endl;
	cout << FactV2<4>::fact << endl;
	cout << std::is_same<int, removeConst<const int>::type>::value << endl;
	cout << std::is_same<int, removeConst<const int>::type>::value << endl;

	cout << is_incrementable<string>::value << endl;
	cout << myis_assignable<int, double>::value << endl;
}
