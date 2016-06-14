//Given an integer matrix, find the length of the longest increasing path.
//
//From each cell, you can either move to four directions : left, right, up or down.You may NOT move diagonally or move outside of the boundary(i.e.wrap - around is not allowed).
//
//Example 1 :
//nums = [
//	[9, 9, 4],
//		[6, 6, 8],
//		[2, 1, 1]
//]
//
//
//
//Return 4
//The longest increasing path is[1, 2, 6, 9].
//
//Example 2:
//nums = [
//	[3, 4, 5],
//		[3, 2, 6],
//		[2, 2, 1]
//]
//
//
//
//Return 4
//The longest increasing path is[3, 4, 5, 6].Moving diagonally is not allowed.

#include <vector>
#include <algorithm>

using namespace std;

static const int directions_num = 4;
static const vector< vector<int> > directions = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

int calculateState(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& state)
{
	if (i < 0 || i >= m || j < 0 || j >= n)
		return 0;
	if (state[i][j] > 0)
		return state[i][j];
	int currentMax = 0;
	for (int k = 0; k < directions_num; ++k)
	{
		int new_i = i + directions[k][0];
		int new_j = j + directions[k][1];
		if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n)
		{
			if (matrix[new_i][new_j] > matrix[i][j])
				currentMax = max(currentMax, calculateState(new_i, new_j, m, n, matrix, state));
		}
	}
	state[i][j] = currentMax + 1;
	return state[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	if (m == 0)
		return 0;
	int n = matrix[0].size();
	if (n == 0)
		return 0;
	int result = 0;
	vector< vector<int> > state(m, vector<int>(n, 0));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			result = max(result, calculateState(i, j, m, n, matrix, state));
		}
	}
	return result;
}