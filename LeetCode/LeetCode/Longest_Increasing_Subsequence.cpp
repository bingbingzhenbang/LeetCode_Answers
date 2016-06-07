//Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//For example,
//Given[10, 9, 2, 5, 3, 7, 101, 18],
//The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//Your algorithm should run in O(n2) complexity.
//
//Follow up : Could you improve it to O(n log n) time complexity ?

#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int len, int dest)
{
	if (dest <= arr[0])
		return 0;
	else if (dest >= arr[len - 1])
		return len;
	else
	{
		int start = 0, last = len - 1, mid = 0;
		while (start + 1 < last)
		{
			mid = (start + last) / 2;
			if (arr[mid] > dest)
				last = mid;
			else if (arr[mid] < dest)
				start = mid;
			else
				return mid;
		}
		return start + 1;
	}
}

int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	int size = nums.size(), currentLen = 1;
	vector<int> y(size, INT_MAX);
	y[0] = nums[0];
	for (int i = 1; i < size; ++i)
	{
		int pos = binarySearch(y, currentLen, nums[i]);
		if (pos == currentLen)
		{
			y[pos] = nums[i];
			++currentLen;
		}
		else
		{
			if (y[pos] > nums[i])
				y[pos] = nums[i];
		}
	}
	return currentLen;
}

void testLengthOfLIS()
{
	vector<int> nums = { 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12 };
	//vector<int> nums = { 2, 2 };
	int rt = lengthOfLIS(nums);
}