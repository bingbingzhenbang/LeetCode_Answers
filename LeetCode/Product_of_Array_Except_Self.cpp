//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//	Solve it without division and in O(n).
//
//	For example, given [1,2,3,4], return [24,12,8,6]. 
//
//	Follow up:
//Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

#include <vector>
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
	int sz = nums.size();
	vector<int> result(sz, 1);
	for (int i = 0; i < sz - 1; ++i)
		result[i+1] = result[i] * nums[i];
	int right = nums[sz-1];
	for (int i = sz - 2; i >=0; --i)
	{
		result[i] *= right;
		right *= nums[i];
	}
	return result;
}

void testProductExceptSelf()
{
	int arr[] = {1,2};
	vector<int> nums, rt;
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
		nums.push_back(arr[i]);

	rt = productExceptSelf(nums);
}