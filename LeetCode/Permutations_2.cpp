//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1, 1, 2] have the following unique permutations :
//[
//	[1, 1, 2],
//	[1, 2, 1],
//	[2, 1, 1]
//]

#include <vector>
#include <algorithm>

using namespace std;

void subPermute(vector<int> num, int begin, int end, vector< vector<int> > &result)
{
	if (begin == end - 1)
		result.push_back(num);
	else
	{
		subPermute(num, begin + 1, end, result);
		for (int k = begin + 1; k < end; ++k)
		{
			if (num[k] == num[begin])
				continue;
			swap(num[begin], num[k]);
			subPermute(num, begin + 1, end, result);
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector< vector<int> > result;
	subPermute(nums, 0, nums.size(), result);
	return result;
}