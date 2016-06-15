//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example :
//Given array A = [2, 3, 1, 1, 4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note :
//	 You can assume that you can always reach the last index.

#include <vector>
#include <algorithm>

using namespace std;

int getSetp(int dest, vector<int> &nums, vector<int> &steps)
{
	int size = nums.size();
	if (dest < 0 || dest >= size)
		return 0;
	if (steps[dest] != INT_MAX)
		return steps[dest];
	int minStep = INT_MAX;
	for (int i = 0; i < dest; ++i)
	{
		int prevMin = getSetp(i, nums, steps);
		if (i + nums[i] >= dest)
			minStep = min(minStep, prevMin + 1);
	}
	steps[dest] = minStep;
	return steps[dest];
}

int bruteJump(vector<int>& nums)
{
	int size = nums.size();
	if (size == 0)
		return 0;
	vector<int> steps(size, INT_MAX);
	steps[0] = 0;
	return getSetp(size - 1, nums, steps);
}

int jump(vector<int>& nums)
{
	int size = nums.size();
	if (size <= 1)
		return 0;
	int level = 0, levelBegin = 0, levelEnd = 0, nextEnd = 0;
	while (levelEnd - levelBegin + 1 > 0)
	{
		++level;
		for (int i = levelBegin; i <= levelEnd; ++i)
		{
			nextEnd = max(nextEnd, i + nums[i]);
			if (nextEnd >= size - 1)
				return level;
		}
		levelBegin = levelEnd + 1;
		levelEnd = nextEnd;
	}
	return 0;
}

void testJump()
{
	vector<int> nums = { 2, 3, 1, 1, 4 };
	//vector<int> nums = { 0 };
	int rt1 = bruteJump(nums);
	int rt2 = jump(nums);
}