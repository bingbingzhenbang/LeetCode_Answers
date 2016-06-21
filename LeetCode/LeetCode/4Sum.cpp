//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
//
//Note : The solution set must not contain duplicate quadruplets.
//	   For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//	   A solution set is :
//[
//	[-1, 0, 0, 1],
//	[-2, -1, 1, 2],
//	[-2, 0, 0, 2]
//]

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	int size = nums.size();
	if (size < 4)
		return vector<vector<int>>();
	sort(nums.begin(), nums.end());
	unordered_map<int, vector< pair<int, int> > > num_pair;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
			num_pair[nums[i] + nums[j]].push_back(pair<int, int>(i, j));
	}
	vector< vector<int> > result;
	for (int i = 0; i < size - 3; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < size - 2; ++j)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;
			int res = target - nums[i] - nums[j];
			unordered_map<int, vector< pair<int, int> > >::iterator mitr = num_pair.find(res);
			if (mitr == num_pair.end())
				continue;
			vector< pair<int, int> > &vec = mitr->second;
			for (auto itr = vec.begin(); itr != vec.end(); ++itr)
			{
				int p = itr->first, q = itr->second;
				if (p <= j)
					continue;
				if (!result.empty() && result.back()[0] == nums[i] && result.back()[1] == nums[j] && result.back()[2] == nums[p])
					continue;
				vector<int> temp({ nums[i], nums[j], nums[p], nums[q] });
				result.push_back(temp);
			}
		}
	}
	return result;
}