//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
//
//
//	For example,
//
//	Consider the following matrix: 
//[
//	[1,   4,  7, 11, 15],
//	[2,   5,  8, 12, 19],
//	[3,   6,  9, 16, 22],
//	[10, 13, 14, 17, 24],
//	[18, 21, 23, 26, 30]
//]

#include <vector>

using namespace std;

bool searchSubMatrix(vector< vector<int> >& matrix, int row_start, int row_end, int col_start, int col_end, int target)
{
	if (row_start > row_end || col_start > col_end)
		return false;
	if (matrix[row_start][col_start] > target || matrix[row_end][col_end] < target)
		return false;
	int row_mid = (row_start + row_end) / 2, col_mid = (col_start + col_end) / 2;
	int num_mid = matrix[row_mid][col_mid];
	if (num_mid == target)
		return true;
	else if (num_mid > target)
	{
		return searchSubMatrix(matrix, row_start, row_mid - 1, col_start, col_mid - 1, target)
			|| searchSubMatrix(matrix, row_mid, row_end, col_start, col_mid - 1, target)
			|| searchSubMatrix(matrix, row_start, row_mid - 1, col_mid, col_end, target);
	}
	else
	{
		return searchSubMatrix(matrix, row_mid + 1, row_end, col_mid + 1, col_end, target)
			|| searchSubMatrix(matrix, row_mid + 1, row_end, col_start, col_mid, target)
			|| searchSubMatrix(matrix, row_start, row_mid, col_mid + 1, col_end, target);
	}
}

bool searchMatrix2(vector< vector<int> >& matrix, int target)
{
	int row_num = matrix.size();
	if (row_num == 0)
		return false;
	int col_num = matrix[0].size();
	if (col_num == 0)
		return false;
	return searchSubMatrix(matrix, 0, row_num - 1, 0, col_num - 1, target);
}

void testSearchMatrix2()
{
	int arr[][5] = {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}};
	int row = sizeof(arr)/sizeof(arr[0]);
	int col = sizeof(arr[0])/sizeof(int);
	vector< vector<int> > mat(row, vector<int>(col));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			mat[i][j] = arr[i][j];
	}
	bool rt = searchMatrix2(mat, 13);
}

