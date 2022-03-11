#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void mean(vector<int>& num1, vector<int>& num2)
{
	vector<int> merge;
	
	int current_index = 0;
	for (int i = 0; i < num1.size(); i++)
	{
		int index = find(num2, current_index, num1[i]);
		while (current_index <= index)
			merge.push_back(num2[current_index++]);
		merge.push_back(num1[i]);

		if (merge.size() > (m + n) / 2)
			return merge[(m + n) / 2]
	}

	for (int i = current_index; i < num2.size(); i++)
		merge.push_back(num2[i]);

}

int main()
{
	vector<int> num1 = {1,3,5};
	vector<int> num2 = {2,4,6};

	cout << mean(num1, num2) << endl;
	return 0;
}
