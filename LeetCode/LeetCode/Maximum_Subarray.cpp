//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array[-2, 1, -3, 4, -1, 2, 1, -5, 4],
//the contiguous subarray [4, -1, 2, 1] has the largest sum = 6.

#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray1(vector<int>& nums)
{
	int sz = nums.size(), maxSum = 0;
	for (int i = 0; i < sz; ++i)
	{
		for (int j = i; j < sz; ++j)
		{
			int thisSum = 0;
			for (int k = i; k <= j; ++k)
				thisSum += nums[k];
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

int maxSubArray2(vector<int>& nums)
{
	int sz = nums.size(), maxSum = 0;
	for (int i = 0; i < sz; ++i)
	{
		int thisSum = 0;
		for (int j = i; j < sz; ++j)
		{
			thisSum += nums[j];
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

int maxSubArray(vector<int>& nums)
{
	int sz = nums.size(), maxSum = 0, thisSum = 0;
	if (sz == 0)
		return 0;
	maxSum = nums[0];
	for (int j = 0; j < sz; ++j)
	{
		thisSum += nums[j];
		if (thisSum > maxSum)
			maxSum = thisSum;
		if (thisSum < 0)
			thisSum = 0;
	}
	return maxSum;
}

void testMaxSubArray()
{
	//vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> nums = { -3, -2, 0, -1 };
	int rt1 = maxSubArray1(nums);
	int rt2 = maxSubArray2(nums);
	int rt = maxSubArray(nums);
}