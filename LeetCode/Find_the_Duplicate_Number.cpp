//Given an array nums containing n + 1 integers where each integer is between 1 and n(inclusive), prove that at least one duplicate number must exist.Assume that there is only one duplicate number, find the duplicate one.
//
//Note:
//
//1.You must not modify the array(assume the array is read only).
//2.You must use only constant, O(1) extra space.
//3.Your runtime complexity should be less than O(n2).
//4.There is only one duplicate number in the array, but it could be repeated more than once.

#include <vector>
#include <algorithm>

using namespace std;

int findDuplicate(vector<int>& nums)
{
	int size = nums.size();
	int small = 1, big = nums.size() - 1;
	while (small < big)
	{
		int mid = (small + big) / 2, cnt = 0;
		for (int i = 0; i < size; ++i)
		{
			if (nums[i] <= mid)
				++cnt;
		}
		if (cnt > mid)
			big = mid;
		else
			small = mid + 1;
	}
	return small;
}