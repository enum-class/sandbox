#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int longest(string in)
{
	stack<char> stk;
	stack<int> counter;
	int maxCounter = 0;

	for (int i = 0; i < in.size(); i++)
	{
		if (in[i] == ')')
		{
			if (!stk.empty())
			{
				stk.pop();
				counter.top() += 2;
			}
			else
			{
				// find max counter, and clean the state
			}
		}
		else
		{
			if (stk.empty())
				counter.push(0);
			stk.push(in[i]);
		}
	}

	return maxCounter > counter ? maxCounter : counter;
}

int main()
{
	string s = "())()()";
	cout << longest(s) << endl;
	return 0;
}
