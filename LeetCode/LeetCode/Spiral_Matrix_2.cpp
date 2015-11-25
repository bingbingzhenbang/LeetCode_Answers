//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//You should return the following matrix : [
//	[1, 2, 3],
//		[8, 9, 4],
//		[7, 6, 5]
//]

#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
	if (n <= 0)
		return vector<vector<int>>();
	vector<vector<int>> matrix(n, vector<int>(n));
	int x0 = 0, y0 = 0, x1 = n - 1, y1 = n - 1, current = 0;
	while (x0 <= x1 && y0 <= y1)
	{
		for (int j = y0; j < y1; ++j)
			matrix[x0][j] = ++current;
		for (int i = x0; i < x1; ++i)
			matrix[i][y1] = ++current;
		for (int j = y1; j > y0; --j)
			matrix[x1][j] = ++current;
		for (int i = x1; i > x0; --i)
			matrix[i][y0] = ++current;
		++x0; ++y0;
		--x1; --y1;
	}
	if (n % 2)
		matrix[--x0][--y0] = ++current;
	return matrix;
}

void testGenerateMatrix()
{
	vector<vector<int>> rt = generateMatrix(1);
}