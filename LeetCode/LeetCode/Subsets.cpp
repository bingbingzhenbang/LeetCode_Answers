//Given a set of distinct integers, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//	  For example,
//	  If nums = [1, 2, 3], a solution is :
//
//[
//	[3],
//	[1],
//	[2],
//	[1, 2, 3],
//	[1, 3],
//	[2, 3],
//	[1, 2],
//	[]
//]

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void getSubsets1(vector<int> one_result, vector<int> &nums, int begin, int end, vector< vector<int> > &result)
{
	if (begin == end - 1)
	{
		result.push_back(one_result);
		one_result.push_back(nums[begin]);
		result.push_back(one_result);
	}
	else
	{
		getSubsets1(one_result, nums, begin + 1, end, result);
		one_result.push_back(nums[begin]);
		getSubsets1(one_result, nums, begin + 1, end, result);
	}
}

vector<vector<int>> subsets1(vector<int>& nums)
{
	vector< vector<int> > result;
	getSubsets1(vector<int>(), nums, 0, nums.size(), result);
	return result;
}

void getSubsets2(vector<int> &sub, vector<int> &nums, int start, vector< vector<int> > &result)
{
	result.push_back(sub);
	int size = nums.size();
	for (int i = start; i < size; ++i)
	{
		sub.push_back(nums[i]);
		getSubsets2(sub, nums, i + 1, result);
		sub.pop_back();
	}
}

vector<vector<int>> subsets2(vector<int>& nums)
{
	vector< vector<int> > result;
	vector<int> sub;
	sort(nums.begin(), nums.end());
	getSubsets2(sub, nums, 0, result);
	return result;
}

vector<vector<int>> subsets3(vector<int>& nums)
{
	vector< vector<int> > result;
	int size = nums.size();
	sort(nums.begin(), nums.end());
	result.push_back(vector<int>());
	for (int i = 0; i < size; ++i)
	{
		int prevSize = result.size();
		for (int j = 0; j < prevSize; ++j)
		{
			vector<int> newsub = result[j];
			newsub.push_back(nums[i]);
			result.push_back(newsub);
		}
	}
	return result;
}

vector<vector<int>> subsets4(vector<int>& nums)
{
	int size = nums.size();
	sort(nums.begin(), nums.end());
	int subsetsnum = pow(2, size);
	vector< vector<int> > result(subsetsnum, vector<int>());
	for (int i = 0; i < subsetsnum; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if ((i >> j) & 1)
				result[i].push_back(nums[j]);
		}
	}
	return result;
}