//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example :
//A = [2, 3, 1, 1, 4], return true.
//
//A = [3, 2, 1, 0, 4], return false.

#include <Vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums)
{
	int size = nums.size(), currentMax = 0;
	for (int i = 0; i < size; ++i)
	{
		if (i > currentMax)
			return false;
		currentMax = max(currentMax, i + nums[i]);
	}
	return true;
}

void testCanJump()
{
	vector<int> nums = { 2, 3, 1, 1, 4 };
	bool rt = canJump(nums);
}