//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given[1, 2, 0] return 3,
//and[3, 4, -1, 1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
	int size = nums.size();
	if (size == 0)
		return 1;
	for (int i = 0; i < size; ++i)
	{
		int currentValue = nums[i];
		if (currentValue == i + 1 || currentValue <= 0 || currentValue > size)
			continue;
		swap(nums[i], nums[currentValue - 1]);
		if (nums[i] != nums[currentValue - 1])
			--i;
	}
	for (int i = 0; i < size; ++i)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}
	return size + 1;
}