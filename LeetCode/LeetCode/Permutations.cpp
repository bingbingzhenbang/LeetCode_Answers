//Given a collection of numbers, return all possible permutations. 
//
//	For example,
//	[1,2,3] have the following permutations:
//[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> permute1(vector<int>& nums)
{
	int sz = nums.size();
	vector<vector<int>> all_result;
	if (sz == 1)
	{
		all_result.push_back(nums);
	}
	else
	{
		for (int i = 0; i < sz; ++i)
		{
			vector<int> one_num = nums;
			swap(one_num[i], one_num[sz - 1]);
			int last = one_num[sz - 1];
			one_num.pop_back();
			vector<vector<int>> before_result = permute1(one_num);
			for (int j = 0; j < before_result.size(); ++j)
			{
				before_result[j].push_back(last);
				all_result.push_back(before_result[j]);
			}
		}
	}
	return all_result;
}

vector<vector<int>> permute2(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int size = nums.size();
	vector< vector<int> > result;
	if (size == 1)
	{
		result.push_back(nums);
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			vector<int> onenumber = nums;
			swap(onenumber[0], onenumber[i]);
			int beforebegin = onenumber[0];
			onenumber.erase(onenumber.begin());
			vector< vector<int> > subresult = permute2(onenumber);
			int subsize = subresult.size();
			for (int j = 0; j < subsize; ++j)
			{
				subresult[j].insert(subresult[j].begin(), beforebegin);
				result.push_back(subresult[j]);
			}
		}
	}
	return result;
}

void testPermute()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	vector<vector<int>> rt = permute2(nums);
}