//Given a non - negative integer n, count all numbers with unique digits, x, where 0 ¡Ü x < 10n.
//
//Example:
//Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ¡Ü x < 100, excluding[11, 22, 33, 44, 55, 66, 77, 88, 99])
//
//Hint :
//1.A direct way is to use the backtracking approach.
//2.Backtracking should contains three states which are(the current number, number of steps to get that number and a bitmask which represent which number is marked as visited so far in the current number).Start with state(0, 0, 0) and count all valid number till we reach number of steps equals to 10n.
//3.This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
//4.Let f(k) = count of numbers with unique digits with length equals k.
//5.f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2)[The first factor is 9 because a number cannot start with 0].

#include <vector>

using namespace std;

int countNumbersWithUniqueDigits(int n)
{
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else
	{
		vector<int> dp(n + 1, 1);
		dp[1] = 10;
		for (int i = 2; i <= n; ++i)
		{
			if (i >= 11)
				dp[i] = dp[i - 1];
			else
				dp[i] = dp[i - 1] + (11 - i) * (dp[i - 1] - dp[i - 2]);
		}
		return dp[n];
	}
}