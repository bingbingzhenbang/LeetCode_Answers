//Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	int sz = nums.size();
	set<int> bst;
	for (int i = 0; i < sz; ++i)
	{
		if (i > k)
			bst.erase(nums[i - k - 1]);
		int n = nums[i];
		auto l = bst.lower_bound(n - t);
		if (l != bst.end() && abs(*l - n) <= t)
			return true;
		bst.insert(n);
	}
	return false;
}

void testContainsNearbyAlmostDuplicate()
{
	vector<int> nums = {4, 2};
	bool rt = containsNearbyAlmostDuplicate(nums, 2, 1);
}