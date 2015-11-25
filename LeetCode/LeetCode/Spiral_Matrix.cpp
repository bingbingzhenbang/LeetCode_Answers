//Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix :
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//
//
//You should return[1, 2, 3, 6, 9, 8, 7, 4, 5].

#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	int row_num = matrix.size();
	if (row_num == 0)
		return vector<int>();
	int col_num = matrix[0].size();
	if (col_num == 0)
		return vector<int>();
	int total_sz = row_num * col_num, currentIndex = 0;
	vector<int> result(total_sz, 0);
	if (row_num == 1)
	{
		for (int j = 0; j < col_num; ++j)
			result[currentIndex++] = matrix[0][j];
	}
	else if (col_num == 1)
	{
		for (int i = 0; i < row_num; ++i)
			result[currentIndex++] = matrix[i][0];
	}
	else
	{
		int x0 = 0, y0 = 0, x1 = row_num - 1, y1 = col_num - 1;
		while (x0 <= x1 && y0 <= y1)
		{
			for (int j = y0; j < y1; ++j)
				result[currentIndex++] = matrix[x0][j];
			for (int i = x0; i < x1; ++i)
				result[currentIndex++] = matrix[i][y1];
			for (int j = y1; j > y0; --j)
				result[currentIndex++] = matrix[x1][j];
			for (int i = x1; i > x0; --i)
				result[currentIndex++] = matrix[i][y0];
			++x0; ++y0;
			--x1; --y1;
		}
		if (row_num % 2 && col_num % 2)
			result[currentIndex++] = matrix[--x0][--y0];
	}
	return result;
}

void testSpiralOrder()
{
	//vector<vector<int>> matrix = { { 1, 2 }, { 4, 5 }, {7, 8 } };
	//vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	//vector<vector<int>> matrix = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 }, { 10 } };
	//vector<vector<int>> matrix = { { 6, 9, 7 } };
	vector<vector<int>> matrix = { { 1, 2, 3 }, {4, 5, 6} };
	vector<int> rt = spiralOrder(matrix);
}