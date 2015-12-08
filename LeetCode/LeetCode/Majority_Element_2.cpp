//Given an integer array of size n, find all elements that appear more than [ n / 3 ] times.The algorithm should run in linear time and in O(1) space.

#include <vector>
#include <algorithm>

using namespace std;

vector<int> majorityElement2(vector<int>& nums)
{
	int sz = nums.size(), n1 = 0, n2 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < sz; ++i)
	{
		int x = nums[i];
		if (x == n1)
			++cnt1;
		else if (x == n2)
			++cnt2;
		else if (cnt1 == 0)
		{
			n1 = x;
			++cnt1;
		}
		else if (cnt2 == 0)
		{
			n2 = x;
			++cnt2;
		}
		else
		{
			--cnt1;
			--cnt2;
		}
	}
	cnt1 = 0;
	cnt2 = 0;
	for (int i = 0; i < sz; ++i)
	{
		int x = nums[i];
		if (x == n1)
			++cnt1;
		else if (x == n2)
			++cnt2;
	}
	vector<int> ret;
	if (cnt1 > sz / 3)
		ret.push_back(n1);
	if (cnt2 > sz / 3)
		ret.push_back(n2);
	return ret;
}

void testMajorityElement2()
{
	vector<int> nums = { 0, 0, 0 };
	vector<int> rt = majorityElement2(nums);
}