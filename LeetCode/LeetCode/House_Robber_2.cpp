//Note: This is an extension of House Robber.
//
//	After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention.This time, all houses at this place are arranged in a circle.That means the first house is the neighbor of the last one.Meanwhile, the security system for these houses remain the same as for those in the previous street.
//
//	Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include <vector>
#include <algorithm>

using namespace std;

int rob2(vector<int>& nums)
{
	int sz = nums.size();
	if (sz == 1)
		return nums[0];
	int notRobCurrent = 0, robCurrent = 0;
	for (int i = 0; i < sz - 1; ++i)
	{
		int temp = notRobCurrent;
		notRobCurrent = max(notRobCurrent, robCurrent);
		robCurrent = temp + nums[i];
	}
	int first = max(notRobCurrent, robCurrent);
	notRobCurrent = 0;
	robCurrent = 0;
	for (int i = 1; i < sz; ++i)
	{
		int temp = notRobCurrent;
		notRobCurrent = max(notRobCurrent, robCurrent);
		robCurrent = temp + nums[i];
	}
	int second = max(notRobCurrent, robCurrent);
	return max(first, second);
}