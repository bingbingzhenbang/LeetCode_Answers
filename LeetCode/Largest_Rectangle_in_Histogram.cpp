//Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given heights = [2, 1, 5, 6, 2, 3],
//return 10.
//the height of the largest rectangle must be the height of one bar
//the following loop invariant is maintained :
//if the indexes stored in stack from bottom to top are
//i_1, i_2, ..., i_k, i_k+1, then
//height[i_1] <= height[i_2] <= ... <= height[i_k] <= height[i_k+1]
//and for any j that i_k < j < i_k+1 height[j] > height[i_k] and height[j] > height[i_k+1]

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
	int size = heights.size();
	heights.push_back(0);
	stack<int> s;
	int maxArea = 0;
	for (int i = 0; i <= size; ++i)
	{
		while (!s.empty() && heights[s.top()] > heights[i])
		{
			int lefth = heights[s.top()];
			s.pop();
			int len = (s.empty() ? i : (i - s.top() - 1));
			maxArea = max(maxArea, lefth * len);
		}
		s.push(i);
	}
	return maxArea;
}

void testLargestRectangleArea()
{
	//vector<int> h = { 2, 1, 2 };
	vector<int> h = { 4, 2, 0, 3, 2, 5 };
	int rt = largestRectangleArea(h);
}