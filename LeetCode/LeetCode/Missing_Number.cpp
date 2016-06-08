//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//For example,
//Given nums = [0, 1, 3] return 2.
//
//Note:
//Your algorithm should run in linear runtime complexity.Could you implement it using only constant extra space complexity ?

#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
	long n = nums.size(), sum = 0;
	for (int i = 0; i < n; ++i)
		sum += nums[i];
	return n * (n + 1) / 2 - sum;
}