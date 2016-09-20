//Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//11110
//11010
//11000
//00000
//Answer : 1
//
//		 Example 2 :
//
//		 11000
//		 11000
//		 00100
//		 00011
//	 Answer : 3

#include <vector>
#include <algorithm>

using namespace std;

void DFSIsland(vector<vector<char>>& grid, int i, int j, int m, int n)
{
	if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || grid[i][j] == 'x')
		return;
	grid[i][j] = 'x';
	DFSIsland(grid, i - 1, j, m, n);
	DFSIsland(grid, i + 1, j, m, n);
	DFSIsland(grid, i, j - 1, m, n);
	DFSIsland(grid, i, j + 1, m, n);
}

int numIslands(vector<vector<char>>& grid)
{
	int m = grid.size();
	if (m < 1)
		return 0;
	int n = grid[0].size();
	int cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == '1')
			{
				DFSIsland(grid, i, j, m, n);
				++cnt;
			}
		}
	}
	return cnt;
}