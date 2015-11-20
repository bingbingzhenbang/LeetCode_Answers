//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//	For example, given the following triangle
//
//	[
//		[2],
//		[3,4],
//		[6,5,7],
//		[4,1,8,3]
//	]
//
//
//
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
	size_t sz = triangle.size();
	if (sz == 0)
		return 0;
	else if (sz == 1)
		return triangle[0][0];
	vector<int> f = triangle[sz - 1];
	for (int row = sz - 2; row >= 0; --row)
	{
		for (int index = 0; index <= row; ++index)
		{
			f[index] = triangle[row][index] + min(f[index], f[index + 1]);
		}
	}
	return f[0];
}

void testMinimumTotal()
{
	vector<vector<int>> triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 }};
	int rt = minimumTotal(triangle);
}