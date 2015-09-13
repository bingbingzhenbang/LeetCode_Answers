//Given an array of integers, every element appears three times except for one. Find that single one. 
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
//

#include <vector>

using namespace std;

int singleNumber2(vector<int>& nums)
{
	vector<int> bitsum(32, 0);
	int sz = nums.size(), rt = 0;
	for (int i = 0; i < 32; ++i)
	{
		for (int j = 0; j < sz; ++j)
			bitsum[i] += (nums[j]>>i)&1;
		rt |= (bitsum[i]%3)<<i;
	}
	return rt;
}

void testSingleNumber2()
{
	int arr[] = {1, 1, 1, 3, 2, 2, 2};
	vector<int> nums;
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
		nums.push_back(arr[i]);

	int rt = singleNumber2(nums);
}