#include <iostream>
#include <tuple>
#include <type_traits>
#include <functional>

/**
 * In summary, when you need to build a tuple, use:
 *
 * std::make_tuple if you need values in the returned tuple,
 * std::tie if you need lvalue references in the returned tuple,
 * std::forward_as_tuple if you need to keep the types of references of the inputs to build the tuple.
 */

template<typename... Ts>
class X1
{
public:
	explicit X1(Ts const&... values)
	:values_(std::make_tuple(values...))
	{
	}

	std::tuple<Ts const&...> values_;
};

template<typename... Ts>
class X2
{
public:
	explicit X2(Ts const&... values)
	:values_(std::make_tuple(std::ref(values)...))
	{
	}

	std::tuple<Ts const&...> values_;
};

template<typename... Ts>
class X3
{
public:
	explicit X3(Ts const&... values)
	:values_(std::tie(values...))
	{
	}

	std::tuple<Ts const&...> values_;
};

std::string universe()
{
	    return "universe";
}

int main()
{
	/// Undefined Behave
	int i = 42;
	auto s = std::string("universe");

	auto x = X1<int, std::string>(i, s);

	std::cout << "i = " << std::get<0>(x.values_) << '\n';
	std::cout << "s = " << std::get<1>(x.values_) << '\n';
	
	auto myTuple = std::forward_as_tuple(i, universe());
	    
	static_assert(std::is_same<decltype(myTuple), std::tuple<int&, std::string&&>>::value);

	return 0;
}
