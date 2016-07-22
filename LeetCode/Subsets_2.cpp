//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//	  For example,
//	  If nums = [1, 2, 2], a solution is :
//
//[
//	[2],
//	[1],
//	[1, 2, 2],
//	[2, 2],
//	[1, 2],
//	[]
//]

#include <vector>
#include <algorithm>

using namespace std;

void getSubsetsWithDup(vector<int> &sub, vector<int> &nums, int start, vector< vector<int> > &result)
{
	result.push_back(sub);
	int size = nums.size(), prevIndex = start;
	for (int i = start; i < nums.size(); ++i)
	{
		if (i != prevIndex && nums[i] == nums[prevIndex])
			continue;
		prevIndex = i;
		sub.push_back(nums[i]);
		getSubsetsWithDup(sub, nums, i + 1, result);
		sub.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<int> sub;
	vector< vector<int> > result;
	getSubsetsWithDup(sub, nums, 0, result);
	return result;
}