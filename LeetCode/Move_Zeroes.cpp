//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. 
//
//	For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. 
//
//Note:
//
//1.You must do this in-place without making a copy of the array.
//	2.Minimize the total number of operations.

#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
	int sz = nums.size();
	if (sz == 0)
		return;
	int space_beg = -1, space_end = -1;
	for (int i = 0; i < sz; ++i)
	{
		if (nums[i] == 0)
		{
			space_beg = i;
			break;
		}
	}
	for (int i = space_beg + 1; i < sz; ++i)
	{
		if (nums[i] != 0)
		{
			space_end = i - 1;
			break;
		}
	}
	if (space_beg == -1 || space_end == -1)
		return;
	for (int i = space_end + 1; i < sz;)
	{
		if (nums[i] != 0)
		{
			nums[space_beg] = nums[i];
			++space_beg;
			++space_end;
			++i;
		}
		else
		{
			++space_end;
			i = space_end + 1;
		}
	}
	for (int i = space_beg; i <=space_end; ++i)
		nums[i] = 0;
}

void testMoveZeroes()
{
	//int arr[] = {3, 30, 34, 5, 9};
	int arr[] = {3, 0, 1, 0, 3, 12, 0, 0, 0, 1, 0, 5};
	//int arr[] = {1};
	int sz = sizeof(arr)/sizeof(int);
	vector<int> nums(sz);
	for (int i = 0; i < sz; ++i)
		nums[i] = arr[i];
	moveZeroes(nums);
}