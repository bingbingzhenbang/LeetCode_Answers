//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.Return the maximum product you can get.
//
//For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//
//Note: you may assume that n is not less than 2.
//
//Hint:
//1.There is a simple O(n) solution to this problem.
//2.You may check the breaking results of n ranging from 7 to 10 to discover the regularities.

#include <vector>
#include <algorithm>

using namespace std;

int integerBreak(int n)
{
	vector<int> dp(n + 1, 0);
	dp[2] = 1;
	for (int i = 3; i < n + 1; ++i)
	{
		for (int j = 1; j <= i / 2; ++j)
		{
			int temp = max(j, dp[j]) * max(i - j, dp[i - j]);
			dp[i] = max(dp[i], temp);
		}
	}
	return dp[n];
}

int integerBreak2(int n)
{
	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 4;
	vector<int> dp(n + 1, 0);
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	for (int i = 5; i < n + 1; ++i)
		dp[i] = 3 * dp[i - 3];
	return dp[n];
}

void testIntegerBreak()
{
	int rt = integerBreak(10);
}