//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 
//
//	For example: 
//
//Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]. 
//
//Note:
//
//1.The order of the result is not important. So in the above example, [5, 3] is also correct.
//	2.Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//

#include <vector>

using namespace std;

vector<int> singleNumber3(vector<int>& nums)
{
	int sz = nums.size(), a = 0, b = 0, c = 0, lowbit = 0;
	vector<int> result(2);

	for (int i = 0; i < sz; ++i)
		c ^= nums[i];

	lowbit = c & (-c);
	for (int i = 0; i < sz; ++i)
	{
		if (nums[i] & lowbit)
			a ^= nums[i];
		else
			b ^= nums[i];
	}

	result[0] = a;
	result[1] = b;
	return result;
}

void testSingleNumber3()
{
	int arr[] = {1, 2, 1, 3, 2, 5};
	vector<int> nums, rt;
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
		nums.push_back(arr[i]);

	rt = singleNumber3(nums);
}