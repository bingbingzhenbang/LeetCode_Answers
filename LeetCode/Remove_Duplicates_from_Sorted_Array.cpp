//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//	Do not allocate extra space for another array, you must do this in place with constant memory. 
//
//	For example,
//	Given input array nums = [1,1,2], 
//
//	Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 

#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	size_t cnt = 1, i = 0, j = i + 1;
	for (; i < nums.size() - 1;)
	{
		j = i + 1;
		for (; j < nums.size() && nums[i] == nums[j]; ++j)
			;
		if (j < nums.size())
		{
			nums[cnt++] = nums[j];
			i = j;
		}
		else
			++i;
	}
	return cnt;
}

void testRemoveDuplicates()
{
	//int arr[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5};
	int arr[] = {1, 1, 2, 2};
	//int arr[] = {-3,-3,-2,-1,-1,0,0,0,0,0};
	int sz = sizeof(arr)/sizeof(int);
	vector<int> nums(sz);
	for (int i = 0; i < sz; ++i)
		nums[i] = arr[i];
	int rt = removeDuplicates(nums);
}