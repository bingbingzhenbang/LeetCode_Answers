//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.

#include <vector>

using namespace std;

int finMinIndex(vector<int>& nums)
{
	int size = nums.size();
	if (size == 1)
		return 0;
	int left = 0, right = size - 1;
	while (nums[left] > nums[right])
	{
		int mid = (left + right) / 2;
		if (nums[mid] > nums[right])
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

int search(vector<int>& nums, int target)
{
	int size = nums.size();
	if (size == 0)
		return -1;
	int minIndex = finMinIndex(nums), maxIndex;
	if (minIndex == 0)
		maxIndex = size - 1;
	else
		maxIndex = minIndex - 1;
	int left, right;
	if (target <= nums[size - 1])
	{
		left = minIndex;
		right = size - 1;
	}
	else
	{
		left = 0;
		right = minIndex - 1;
	}
	if (nums[left] > target || nums[right] < target)
		return -1;
	int mid = (left + right) / 2;
	while ((right - left) > 1)
	{
		if (nums[mid] > target)
			right = mid;
		else
			left = mid;
		mid = (left + right) / 2;
	}
	if (nums[mid] == target)
		return mid;
	else if (nums[left + 1] == target)
		return left + 1;
	else
		return -1;
}

void testSearch()
{
	vector<int> nums = { 3, 1 };
	int target = 3;
	int index = search(nums, target);
}