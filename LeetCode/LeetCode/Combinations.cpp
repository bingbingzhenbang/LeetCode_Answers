//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. 
//
//	For example,
//	If n = 4 and k = 2, a solution is: 
//[
//	[2,4],
//	[3,4],
//	[2,3],
//	[1,2],
//	[1,3],
//	[1,4],
//]

#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> all_result;
	if (k == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			vector<int> one_result(1, i + 1);
			all_result.push_back(one_result);
		}
	}
	else
	{
		if (k <= n)
		{
			vector<vector<int>> one_result = combine(n - 1, k);
			for (vector<vector<int>>::iterator itr = one_result.begin();
				itr != one_result.end(); ++itr)
			{
				all_result.push_back(*itr);
			}
			vector<vector<int>> two_result = combine(n - 1, k - 1);
			for (vector<vector<int>>::iterator itr = two_result.begin();
				itr != two_result.end(); ++itr)
			{
				itr->push_back(n);
				all_result.push_back(*itr);
			}
		}
	}
	return all_result;
}

void testCombine()
{
	vector<vector<int>> rt = combine(4, 4);
}
