//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
//Integers in each row are sorted from left to right.
//	The first integer of each row is greater than the last integer of the previous row.
//
//
//	For example,
//
//	Consider the following matrix: 
//[
//	[1,   3,  5,  7],
//	[10, 11, 16, 20],
//	[23, 30, 34, 50]
//]
//

#include <vector>

using namespace std;

bool searchMatrix(vector< vector<int> >& matrix, int target)
{
	int row_num = matrix.size();
	if (row_num == 0)
		return false;
	int col_num = matrix[0].size();
	if (col_num == 0)
		return false;
	if (matrix[0][0] > target || matrix[row_num - 1][col_num - 1] < target)
		return false;
	int dst_row;
	if (row_num == 1)
		dst_row = 0;
	else if (matrix[0][col_num - 1] >= target)
		dst_row = 0;
	else if (matrix[row_num - 1][0] <= target)
		dst_row = row_num - 1;
	else
	{
		int first_row = 0, last_row = row_num - 1;
		int mid_row = (first_row + last_row) / 2;
		while ( !( matrix[mid_row][0] <= target && matrix[mid_row][col_num - 1] >= target ) && first_row < last_row)
		{
			if (matrix[mid_row][col_num - 1] < target)
				first_row = mid_row + 1;
			else if (matrix[mid_row][0] > target)
				last_row = mid_row - 1;
			mid_row = (first_row + last_row) / 2;
		}
		dst_row = mid_row;
	}
	if (matrix[dst_row][0] > target || matrix[dst_row][col_num - 1] < target)
		return false;
	int dst_col;
	if (col_num == 1)
		dst_col = 0;
	else
	{
		int first_col = 0, last_col = col_num - 1;
		int mid_col = (first_col + last_col)/2;
		while (matrix[dst_row][mid_col] != target && first_col <  last_col)
		{
			if (matrix[dst_row][mid_col] < target)
				first_col = mid_col + 1;
			else if (matrix[dst_row][mid_col] > target)
				last_col = mid_col - 1;
			mid_col = (first_col + last_col)/2;
		}
		dst_col = mid_col;
	}
	return matrix[dst_row][dst_col] == target;
}

void testSearchMatrix()
{
	int arr[][4]={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	int row = sizeof(arr)/sizeof(arr[0]);
	int col = sizeof(arr[0])/sizeof(int);
	vector< vector<int> > mat(row, vector<int>(col));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			mat[i][j] = arr[i][j];
	}
	bool rt = searchMatrix(mat, 13);
}