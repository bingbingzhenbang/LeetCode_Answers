//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees(clockwise).
//
//Follow up :
//Could you do this in - place ?

#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
	size_t demension = matrix.size();
	if (demension == 0 && demension == 1)
		return;
	size_t row_half = demension / 2;
	size_t col_half = (demension % 2) ? row_half + 1 : row_half;
	for (size_t i = 0; i < row_half; ++i)
	{
		for (size_t j = 0; j < col_half; ++j)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[demension - 1 - j][i];
			matrix[demension - 1 - j][i] = matrix[demension - 1 - i][demension - 1 - j];
			matrix[demension - 1 - i][demension - 1 - j] = matrix[j][demension - 1 - i];
			matrix[j][demension - 1 - i] = temp;
		}
	}
}

void testRotate()
{
	vector<vector<int>> matrix = { { 1, 2 }, { 3, 4 } };
	rotate(matrix);
}