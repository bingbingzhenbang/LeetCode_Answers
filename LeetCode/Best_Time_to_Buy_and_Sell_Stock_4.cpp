//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most k transactions.
//
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

#include <vector>
#include <algorithm>

using namespace std;

//hold[k][i]  ith day k transaction have stock and maximum profit
//unhold[k][i] ith day k transaction do not have stock at hand and maximum profit
//in each transaction buy and sell

int maxProfit4(int k, vector<int>& prices)
{
	int size = prices.size();
	if (size < 2)
		return 0;
	if (k > size / 2)
	{
		int result = 0;
		for (int i = 1; i < size; ++i)
		{
			if (prices[i] > prices[i - 1])
				result += prices[i] - prices[i - 1];
		}
		return result;
	}
	vector< vector<int> > hold(k + 1, vector<int>(size, 0));
	vector< vector<int> > unhold(k + 1, vector<int>(size, 0));
	for (int i = 0; i <= k; ++i)
		hold[i][0] = -prices[0];
	for (int j = 1; j < size; ++j)
		hold[0][j] = max(hold[0][j - 1], -prices[j]);
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j < size; ++j)
		{
			hold[i][j] = max(hold[i][j - 1], unhold[i - 1][j] - prices[j]);
			unhold[i][j] = max(unhold[i][j - 1], hold[i][j] + prices[j]);
		}
	}
	return max(hold[k][size - 1], unhold[k][size - 1]);
}

void testMaxProfit4()
{
	int k = 2;
	vector<int> prices = { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0 };
	int rt = maxProfit4(k, prices);
}