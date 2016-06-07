//Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.

#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	if (m == 0)
		return 0;
	int n = grid[0].size();
	if (n == 0)
		return 0;
	vector< vector<int> > path_sum(m, vector<int>(n, grid[0][0]));
	for (int j = 1; j < n; ++j)
		path_sum[0][j] = path_sum[0][j - 1] + grid[0][j];
	for (int i = 1; i < m; ++i)
		path_sum[i][0] = path_sum[i - 1][0] + grid[i][0];
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			path_sum[i][j] = min(path_sum[i - 1][j], path_sum[i][j - 1]) + grid[i][j];
		}
	}
	return path_sum[m - 1][n - 1];
}