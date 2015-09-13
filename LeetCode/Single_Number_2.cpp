//Given an array of integers, every element appears three times except for one. Find that single one. 
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
//

#include <vector>

using namespace std;

int singleNumber2(vector<int>& nums)
{
	//vector<int> bitsum(32, 0);
	//int sz = nums.size(), rt = 0;
	//for (int i = 0; i < 32; ++i)
	//{
	//	for (int j = 0; j < sz; ++j)
	//		bitsum[i] += (nums[j]>>i)&1;
	//	rt |= (bitsum[i]%3)<<i;
	//}
	//return rt;
	int one_or_two = 0, two = 0, three = 0;
	int sz = nums.size();
	for (int i = 0; i < sz; ++i)
	{
		int tmp = nums[i];
		three = two & tmp;
		two |= one_or_two & tmp;
		one_or_two |= tmp;

		two &= ~three;
		one_or_two &= ~three;
	}

	return one_or_two;
}

void testSingleNumber2()
{
	int arr[] = {1, 1, 1, 4, 2, 2, 2, 4, 4, 5};
	vector<int> nums;
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
		nums.push_back(arr[i]);

	int rt = singleNumber2(nums);
}