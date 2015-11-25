//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and(i, 0).Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container.

#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height)
{
	int sz = height.size();
	if (sz == 0 || sz == 1)
		return 0;
	int capacity = 0, left = 0, right = sz - 1;
	while (left < right)
	{
		int water = min(height[left], height[right]) * (right - left);
		if (water > capacity)
			capacity = water;
		if (height[left] < height[right])
			++left;
		else
			--right;
	}
	return capacity;
}