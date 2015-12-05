//Given an array of size n, find the majority element.The majority element is the element that appears more than [ n / 2 ] times.
//
//You may assume that the array is non - empty and the majority element always exist in the array.

#include <vector>
#include <algorithm>

using namespace std;

int majorityElement1(vector<int>& nums)
{
	int sz = nums.size();
	sort(nums.begin(), nums.end());
	return nums[sz / 2];
}

int majorityElement(vector<int>& nums)
{
	int sz = nums.size(), rt = 0, cnt = 0;
	for (int i = 0; i < sz; ++i)
	{
		if (cnt == 0)
		{
			rt = nums[i];
			++cnt;
		}
		else
		{
			if (rt == nums[i])
				++cnt;
			else
				--cnt;
		}
	}
	return rt;
}

void testMajorityElement()
{
	vector<int> nums = { 1, 3, 1, 3 , 3, 1, 3, 5};
	int rt = majorityElement(nums);
}