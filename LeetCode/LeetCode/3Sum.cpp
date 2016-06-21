//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note : The solution set must not contain duplicate triplets.
//	   For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//	   A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	int size = nums.size();
	if (size < 3)
		return vector<vector<int>>();
	sort(nums.begin(), nums.end());
	if (nums[0] > 0 || nums[size - 1] < 0)
		return vector<vector<int>>();
	vector<vector<int>> result;
	for (int i = 0; i < size - 2 && nums[i] <= 0; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		int sum = -nums[i];
		for (int j = i + 1, k = size - 1; j < k;)
		{
			int temp = nums[j] + nums[k];
			if (temp == sum)
			{
				result.push_back(vector<int>{nums[i], nums[j], nums[k]});
				for (; j < size - 2 && nums[j] == nums[j + 1]; ++j)
					;
				++j;
				for (; k > j && nums[k] == nums[k - 1]; --k)
					;
				--k;
			}
			else if (temp < sum)
			{
				++j;
			}
			else
			{
				--k;
			}
		}
	}
	return result;
}