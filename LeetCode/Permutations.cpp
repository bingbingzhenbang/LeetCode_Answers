//Given a collection of numbers, return all possible permutations. 
//
//	For example,
//	[1,2,3] have the following permutations:
//[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 

#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums)
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
			vector<vector<int>> before_result = permute(one_num);
			for (int j = 0; j < before_result.size(); ++j)
			{
				before_result[j].push_back(last);
				all_result.push_back(before_result[j]);
			}
		}
	}
	return all_result;
}

void testPermute()
{
	int arr[] = {1, 2, 3};
	int sz = sizeof(arr)/sizeof(int);
	vector<int> nums(sz);
	for (int i = 0; i < sz; ++i)
		nums[i] = arr[i];
	vector<vector<int>> rt = permute(nums);
}