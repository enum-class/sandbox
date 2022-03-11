#include <iostream>
#include <vector>
#include <array>

using namespace std;
using VarList = vector<unsigned int>;
using Matrix = vector<VarList>;

struct Cell
{
	Cell()
	{
		options.fill(true);
	}
	
	void set(unsigned int num) noexcept
	{
		options.fill(false);
		options.at(num) = true;
		isSet = true;
	}

	void unset(unsigned int num) noexcept
	{
		options.at(num) = false;
	}
	
	bool isAvailable(unsigned int num) const noexcept
	{
		return options.at(num);
	}

	array<bool, 10> options;
	bool isSet = false;
}

bool canInsert(const vector<vector<Cell>>& matrix, unsigned int num, int x,
		int y, size_t size) noexcept
{
	if (x > 0 && y > 0)
		if (matrix[x-1][y-1].isSet && matrix[x-1][y-1].isAvailable(num))
			return false;

	if (x < size && y < size)
		if (matrix[x+1][y+1].isSet && matrix[x+1][y+1].isAvailable(num))
			return false;

	if (x > 0 && y < size)
		if (matrix[x-1][y+1].isSet && matrix[x-1][y+1].isAvailable(num))
			return false;

	if (x < size && y > 0)
		if (matrix[x+1][y-1].isSet && matrix[x+1][y-1].isAvailable(num))
			return false;
}

unsigned int calculateApproximateLength(size_t m) noexcept
{
	if (m < 4)
		return 3
	
	for (int i = 3; i <= int(m/2); i++)
		if (i * i > m)
			return i + 1
}

bool insert(const vector<vector<Cell>>& matrix, unsigned int num, int x, int y) noexcept
{
}

void compute(const VarList& numbers, size_t m) noexcept
{
	length = calculateApproximateLength(m);
	vector<vector<Cell>> matrix;
	matrix.reserve(length);
	for (vector<Cell>& row : matrix)
		row.reserve(length);

	size_t size = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		unsigned int count = numbers[i];
		unsigned int num = i + 1;
		
		while (count > 0)
		{
			bool isInserted = false;

			for (int row = 0; row <= size; row++)
			{
				for (int col = 0; col <= size; col++)
				{
					if (canInsert(matrix, num, row, col, size))
					{
						isInserted = insert(matrix, num, row, col);
						if (row == size || col == size)
							size++;
						break;
					}
				}

				if (isInserted)
					break;
			}

			count--;
		}
	}
}

int main()
{
	size_t test_no = 0;
	cin >> test_no;
	Matrix inputs;
	inputs.reserve(test_no);

	for (size_t i = 0; i < test_no; ++i)
	{
		size_t m = 0;
		size_t k = 0;
		cin >> m >> k;

		for (size_t j = 0; j < k; j++)
		{
			unsigned int var = 0;
			cin >> var;
			inputs[i].push_back(var);
		}

		compute(inputs[i], m);
	}

	return 0;
}
