#ifndef BIG_CLASS_H_
#define BIG_CLASS_H_

template <typename T1, typename T2>
class Glue;

class BigClass;

template <typename derived>
struct Base
{
	const derived& get_ref() const noexcept
	{
		return static_cast<const derived&>(*this);
	}
};

template <typename T1>
struct Depth
{
	static const int num = 0;
};

template <typename T1, typename T2>
struct Depth< Glue<T1, T2> >
{
	static const int num = 1 + Depth<T1>::num;
};

template <typename T1>
struct BigClassPtrs
{
	static const int num = 0;

	static void get_ptrs(const BigClass** ptrs, const T1& X)
	{
		ptrs[0] = reinterpret_cast<const BigClass*>(&X);
	}
};

template <typename T1, typename T2>
struct BigClassPtrs< Glue<T1,T2> >
{
	static const int num = 1 + BigClassPtrs<T1>::num;

	static void get_ptrs(const BigClass** ptrs, const Glue<T1,T2>& X)
	{
		// traverse the left node
		BigClassPtrs<T1>::get_ptrs(ptrs, X.a);

		// get address of the matrix on the right node
		ptrs[num] = reinterpret_cast<const BigClass*>(&X.b);
	}
};

template <typename T1, typename T2>
class Glue : public Base<Glue<T1, T2>>
{
public:
	const T1& a;
	const T2& b;

	Glue(const T1& _a, const T2& _b)
	: a(_a)
	, b(_b)
	{
	}
};

class BigClass : public Base<BigClass>
{
public:
	int value;
	
	BigClass()
	:value(0)
	{
	}

	BigClass(int _a)
	: value(_a)
	{
	}

	template <typename T1, typename T2>
	BigClass(const Glue<T1, T2>& glue)
	{
		operator=(glue);
	}

	template <typename T1, typename T2>
	const BigClass& operator = (const Glue<T1, T2>& glue)
	{
		int N = 1 + Depth< Glue<T1, T2> >::num;
		const BigClass* ptrs[N];

		BigClassPtrs< Glue<T1, T2> >::get_ptrs(ptrs, glue);

		for (size_t i = 0; i < N; i++)
			this->value += ptrs[i]->value;

		return *this;
	}
};

template <typename T1, typename T2>
const Glue<T1, T2> operator + (const Base<T1>& a, const Base<T2>& b)
{
	return Glue<T1, T2>(a.get_ref(), b.get_ref());
}

#endif
