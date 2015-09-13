//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 
//
//	click to show follow up.
//
//	Follow up: 
//Did you use extra space?
//	A straight forward solution using O(mn) space is probably a bad idea.
//	A simple improvement uses O(m + n) space, but still not the best solution.
//	Could you devise a constant space solution? 
//

#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
	int row = matrix.size();
	if (row == 0)
		return;
	int col = matrix[0].size();
	if (col == 0)
		return;

	bool firstRowZero = false, firstColZero = false;
	for (int j = 0; j < col; ++j)
	{
		if (matrix[0][j] == 0)
		{
			firstRowZero = true;
			break;
		}
	}
	for (int i = 0; i < row; ++i)
	{
		if (matrix[i][0] == 0)
		{
			firstColZero = true;
			break;
		}
	}

	for (int i = 1; i < row; ++i)
	{
		if (matrix[i][0] == 0)
			continue;
		else
		{
			for (int j = 1; j < col; ++j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					break;
				}
			}
		}
	}
	for (int j = 1; j < col; ++j)
	{
		if (matrix[0][j] == 0)
			continue;
		else
		{
			for (int i = 1; i < row; ++i)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					break;
				}
			}
		}
	}

	for (int i = 1; i < row; ++i)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 1; j < col; ++j)
				matrix[i][j] = 0;
		}
	}
	for (int j = 1; j < col; ++j)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 1; i < row; ++i)
				matrix[i][j] = 0;
		}
	}

	if (firstRowZero)
	{
		for (int j = 0; j < col; ++j)
			matrix[0][j] = 0;
	}
	if (firstColZero)
	{
		for (int i = 0; i < row; ++i)
			matrix[i][0] = 0;
	}
}