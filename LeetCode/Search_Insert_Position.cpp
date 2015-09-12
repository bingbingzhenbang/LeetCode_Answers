//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//	You may assume no duplicates in the array.
//
//	Here are few examples.
//	[1,3,5,6], 5 ¡ú 2
//	[1,3,5,6], 2 ¡ú 1
//	[1,3,5,6], 7 ¡ú 4
//	[1,3,5,6], 0 ¡ú 0 
//

#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
	int sz = nums.size();
	int beg = 0, end = sz - 1;
	if (target < nums[beg])
		return 0;
	else if (target > nums[end])
		return sz;
	else
	{
		int mid = (beg + end) / 2;
		while ((end - beg) > 1)
		{
			if (nums[mid] > target)
				end = mid;
			else
				beg = mid;
			mid = (beg + end) / 2;
		}
		if (nums[mid] == target)
			return mid;
		else
			return beg + 1;
	}
}

void testsearchInsert()
{
	int arr[] = {1,3,5,6};
	vector<int> nums;
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
		nums.push_back(arr[i]);

	int target = 5;
	int rt = searchInsert(nums, target);
}