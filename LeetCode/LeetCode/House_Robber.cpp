//You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums)
{
	int notRobCurrent = 0, robCurrent = 0, sz = nums.size();
	for (int i = 0; i < sz; ++i)
	{
		int temp = notRobCurrent;
		notRobCurrent = max(notRobCurrent, robCurrent);
		robCurrent = temp + nums[i];
	}
	return max(notRobCurrent, robCurrent);
}