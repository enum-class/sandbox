#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <limits>
#include <set>

using namespace std;

void print(const vector<uint16_t>& numbers) noexcept
{
	for_each(begin(numbers), end(numbers), [](const uint16_t& num) { cout << num << "\t";});
	cout << endl;
}

uint16_t compute(const auto& begin, const auto& end) noexcept
{
	set<uint16_t> s(begin, end);
	uint16_t distance = 0;

	for (uint16_t x : set)
	{
		
	}	
}

uint16_t calculate(const auto& begin, const auto& end, uint16_t partition_no) noexcept
{
	static unordered_map<uint16_t, uint16_t> cache;
	
	if (partition_no == 1)
		return compute(begin, end);

	uint16_t hash = partition_no;
	uint16_t weight = 10;
	for (auto it = begin; it < end; it++)
	{
		hash += *it * weight;
		weight *= 10;
	}

	const auto result = cache.find(hash);
	if (result != cache.end())
	   return result->second;

	uint16_t min = std::numeric_limits<uint16_t>::max();
	for (auto it = begin; it < end; it++)
	{
		uint16_t t_min = compute(begin, it) + calculate(it + 1, end, partition_no - 1);
		if (t_min < min)
			min = t_min;
	}
	
	cache[hash] = min;
	return min;
}

int main()
{
	uint16_t number_no = 0;
	uint16_t partition_no = 0;
	
	cin >> number_no >> partition_no;

	vector<uint16_t> numbers(number_no);

	for_each(begin(numbers), end(numbers), [](uint16_t& num) { cin >> num;});
	
	//cout << compute(numbers.begin(), numbers.end()) << endl;
	cout << calculate(begin(numbers), end(numbers), partition_no) << endl;
	return 0;
}
