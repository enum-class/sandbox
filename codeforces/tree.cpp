#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Tree
{
public:
	vector<vector<int>> tree;
	
	Tree(int n)
	{
		for (int i =0; i < n ; i++)
			tree.emplace_back();
	}

	bool add(int a, int b) noexcept
	{
		if (a == b)
			return false;
		
		if (find(tree[a].begin(), tree[a].end(), b) != tree[a].end())
			return false;

		tree[a].push_back(b);	
		tree[b].push_back(a);	
	}

	void remove(int a, int b) noexcept
	{
		auto result1 = find(begin(tree[a]), end(tree[a]), b);
		tree[a].erase(result1);
		auto result2 = find(begin(tree[b]), end(tree[b]), a);
		tree[b].erase(result2);
	}
	
	void print()
	{
		cout << "====================\n";
		for (int i=0; i<tree.size(); i++)
		{
			cout << i << " | ";
			for (const int& n : tree[i])
				cout << n << "\t";
			cout << endl;	
		}
		cout << endl;
	}

	void compute() noexcept
	{
		vector<vector<int>> outputs;
		print();
		for (int i=0; i<tree.size();)
		{
			if (tree[i].size() > 2)
			{
				int n = tree[i].back();
				remove(n, i);
				for (int j=0; j<tree.size(); j++)
					if (tree[j].size() < 2 && add(j, n))
					{
						outputs.emplace_back();

						outputs.back().push_back(i+1);
						outputs.back().push_back(n+1);
						outputs.back().push_back(j+1);
						outputs.back().push_back(n+1);
						//cout << i + 1 << "\t" << n + 1 << "\t" << j + 1 << "\t" << n + 1 << endl;
						//add(j, n);
						//print();
						break;
					}
			}
			else
				i++;
		}

		cout << outputs.size() << endl;
		for (const vector<int>& row : outputs)
		{
			for (const int& ele : row)
				cout << ele << " ";
			cout << endl;
		}

		print();
	}
};

int main()
{
	size_t test_no = 0;
	size_t node_no = 0;

	cin >> test_no;
	
	while(test_no > 0)
	{
		cin >> node_no;
		Tree tree(node_no);
				
		int n1, n2;
		for (int i=1; i< node_no;++i)
		{
			cin >> n1 >> n2;
			tree.add(n1 - 1, n2 - 1);
		}

		tree.compute();
		--test_no;
	}

	return 0;
}
