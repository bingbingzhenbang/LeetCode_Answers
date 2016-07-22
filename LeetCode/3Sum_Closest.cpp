//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.Return the sum of the three integers.You may assume that each input would have exactly one solution.
//
//For example, given array S = { -1 2 1 - 4 }, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	int size = nums.size();
	int closetsum = nums[0] + nums[1] + nums[2];
	for (int i = 0; i < size - 2; ++i)
	{
		for (int j = i + 1, k = size - 1; j < k;)
		{
			int cursum = nums[i] + nums[j] + nums[k];
			if (cursum == target)
				return cursum;
			if (abs(cursum - target) < abs(closetsum - target))
				closetsum = cursum;
			if (cursum > target)
				--k;
			else
				++j;
		}
	}
	return closetsum;
}