#include <iostream>

class Interface
{
public:
	virtual void fun() const noexcept= 0;
};

/**
 * Local Class:
 * It can be easily proven that any idiom that uses a local class can be implemented using a
 * template class outside the function. In other words, local classes are not an idiom-enabling
 * feature. On the other hand, local classes can simplify implementations and improve local-
 * ity of symbols.
 *
 * cannot define static member variables
 * cannot access nonstatic local variables
 * can use the template parameters of the enclosing function
 * They are final, nobady can drive from them.
 *
 */
template <class T, class U>
Interface* make_adapter(const T& obj, const U& arg)
{
	class Local : public Interface
	{
	public:
		Local(const T& obj, const U& arg)
		: obj_(obj)
		, arg_(arg)
		{
		}

		void fun() const noexcept
		{
			obj_.call(arg_);
		}
	private:
		const T& obj_;
		const U& arg_;
	};

	return new Local(obj, arg);
}

template <int V>
struct Int2Type
{
	enum { value = V};
};

template <typename T, bool isSomething>
struct dummy
{
public:
	void do_something(const T& obj)
	{
		do_something_helper(const T& obj, Int2Type<isSomething>());
	}

private:
	/// These 2 function can not compile at same time; So we can not use if-else
	void do_something_helper(const T& obj, Int2Type<true>);
	void do_something_helper(const T& obj, Int2Type<false>);
};

template<class T, class U>
T* Create(const U& arg)
{
	return new T(arg);
}

/**
 * Partial function specialization:
 *
 * Illegal code — don't try this at home
 * template <class U>
 * Widget* Create<Widget, U>(const U& arg)
 * {
 *		return new Widget(arg,	-1);
 * }
 *
 * Use dummy light weight object
 */
template <typename T>
struct Type2Type
{
	typedef T OriginalType;
};

template<class T, class U>
T* Create(const U& arg, Type2Type<T> /* Dummy object */)
{
	return new T(arg);
}

template<class T, class U>
T* Create(const U& arg, Type2Type<Widget> /* Dummy object */)
{
	return new Widget(arg,	-1);
}

// Use Create()
String* pStr = Create("Hello", Type2Type<String>());
Widget* pW = Create(100, Type2Type<Widget>());


/*
 *	Type selection
 *	First approach
 */
emplate <typename T, bool isPolymorphic>
struct Traits
{
	typedef T* ValueType;
};

template <typename T>
struct Traits<T, false>
{
	typedef T ValueType;
};

template <typename T, bool isPolymorphic>
class NiftyContainer
{
	typedef NiftyContainerValueTraits<T, isPolymorphic> Traits;
	typedef typename Traits::ValueType ValueType;

	vector<ValueType> storage;
};

/*
 *	Type selection
 *	Second approach
 */
template <bool flag, typename T, typename U>
struct Select
{
	typedef T Result;
};

template <typename T, typename U>
struct Select<false, T, U>
{
	typedef U Result;
};

template <typename T, bool isPolymorphic>
class NiftyContainer
{
	typedef typename Select<isPolymorphic, T*, T>::Result ValueType;

	vector<ValueType> storage;
};
