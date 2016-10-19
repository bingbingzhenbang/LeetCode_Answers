//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//For example, given the following matrix :
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 6.

#include <vector>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights);

int maximalRectangle(vector<vector<char>>& matrix)
{
	size_t m = matrix.size();
	if (m == 0)
		return 0;
	size_t n = matrix[0].size();
	if (n == 0)
		return 0;
	vector< vector<int> > dp(m, vector<int>(n, 0));
	for (size_t j = 0; j < n; ++j)
		dp[0][j] = matrix[0][j] - '0';
	for (size_t i = 1; i < m; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (matrix[i][j] == '1')
				dp[i][j] = dp[i - 1][j] + 1;
			else
				dp[i][j] = 0;
		}
	}
	int maxArea = INT_MIN;
	for (size_t i = 0; i < m; ++i)
	{
		int temp = largestRectangleArea(dp[i]);
		maxArea = max(maxArea, temp);
	}
	return maxArea;
}
