#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> Result;

void print_result(const Result& result)
{
	cout << " {  ";
	for (const string& element : result)
		cout << element.c_str() << " ";
	cout << " } " << endl;
}

void all_subsequence(const string& input, Result& result)
{
	if (input.length() < 2)
		return result.push_back(input);
	
	all_subsequence(input.substr(1), result);

	size_t subNo = result.size();
	
	for (int i = 0; i < subNo; i++)
		result.push_back(input[0] + result[i]);

	result.push_back(input.substr(0, 1));
}

bool isSubsetSum(const vector<int>& input, size_t n, int sum)
{
	if (sum == 0) 
		return true;

	if (n == 0) 
		return false; 

	if (input[n - 1] > sum) 
		return isSubsetSum(input, n - 1, sum); 

	return isSubsetSum(input, n - 1, sum) 
		|| isSubsetSum(input, n - 1, sum - input[n - 1]); 
}

void perfectSubset(const vector<int>& input, int sum, vector<vector<int>>& result);

int main()
{
	Result result;
	all_subsequence("aaa", result);
	print_result(result);
	
	vector<int> input = {3, 4, 5, 2};
	cout << isSubsetSum(input, 4, 9) << endl;
	return 0;
}
