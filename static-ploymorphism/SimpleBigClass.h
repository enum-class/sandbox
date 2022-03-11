#ifndef SIMPLE_BIG_CLASS_H_
#define SIMPLE_BIG_CLASS_H_

class SimpleBigClass;

class SimpleGlue
{
public:
	const SimpleBigClass& a;
	const SimpleBigClass& b;

	SimpleGlue(const SimpleBigClass& _a, const SimpleBigClass& _b)
	: a(_a)
	, b(_b)
	{
	}
};

class SimpleBigClass
{
public:
	int value;
	
	SimpleBigClass() = default;

	SimpleBigClass(int _a)
	: value(_a)
	{
	}

	SimpleBigClass(const SimpleGlue& glue)
	{
		operator=(glue);
	}

	const SimpleBigClass& operator = (const SimpleGlue& glue)
	{
		const SimpleBigClass& a = glue.a;
		const SimpleBigClass& b = glue.b;

		this->value = a.value + b.value;

		return *this;
	}

};

const SimpleGlue operator + (const SimpleBigClass& a, const SimpleBigClass& b)
{
	return SimpleGlue(a, b);
}

#endif
