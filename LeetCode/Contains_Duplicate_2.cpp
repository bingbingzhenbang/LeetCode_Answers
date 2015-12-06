//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	int sz = nums.size();
	unordered_map<int, int> numIndex;
	for (int i = 0; i < sz; ++i)
	{
		unordered_map<int, int>::iterator iter = numIndex.find(nums[i]);
		if (iter == numIndex.end())
			numIndex[nums[i]] = i;
		else
		{
			if (i - iter->second <= k)
				return true;
			else
			{
				numIndex[nums[i]] = i;
			}
		}
	}
	return false;
}

void testContainsNearbyDuplicate()
{
	vector<int> nums = { 1, 2, 1 };
	bool rt = containsNearbyDuplicate(nums, 1);
}