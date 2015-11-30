//Given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by array nums.You are asked to burst all the balloons.If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.Here left and right are adjacent indices of i.After the burst, the left and right then becomes adjacent.
//
//Find the maximum coins you can collect by bursting the balloons wisely.
//
//Note:
//(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//(2) 0 ¡Ü n ¡Ü 500, 0 ¡Ü nums[i] ¡Ü 100
//
//Example :
//
//		Given[3, 1, 5, 8]
//
//		Return 167
//		nums = [3, 1, 5, 8] -- > [3, 5, 8] -- > [3, 8]   -- > [8]  -- > []
//		coins = 3 * 1 * 5 + 3 * 5 * 8 + 1 * 3 * 8 + 1 * 8 * 1 = 167

#include <vector>
#include <algorithm>

using namespace std;

int maxCoins(vector<int>& nums)
{
	int sz = nums.size();
	if (sz == 0)
		return 0;
	if (sz == 1)
		return nums[0];
	vector<int> new_nums(sz + 2, 1);
	int new_sz = new_nums.size();
	for (int i = 1; i < new_sz - 1; ++i)
		new_nums[i] = nums[i - 1];
	//dp[i][j] is the maxCoins between i and j
	vector<vector<int>> dp(new_sz, vector<int>(new_sz, 0));
	for (int len = 1; len <= sz; ++len)
	{
		for (int left = 1; left <= sz - len + 1; ++left)
		{
			int right = left + len - 1;
			for (int k = left; k <= right; ++k)
			{
				dp[left][right] = max(dp[left][right], dp[left][k - 1] + new_nums[left - 1] * new_nums[k] * new_nums[right + 1] + dp[k + 1][right]);
			}
		}
	}
	return dp[1][sz];
}

void testMaxCoins()
{
	vector<int> nums = { 3, 1, 5, 8 };
	int rt = maxCoins(nums);
}