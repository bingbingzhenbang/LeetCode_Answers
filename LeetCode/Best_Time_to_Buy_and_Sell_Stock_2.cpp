//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times).However, you may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

#include <vector>

using namespace std;

int maxProfit2(vector<int>& prices)
{
	int sz = prices.size();
	if (sz == 0 || sz == 1)
		return 0;
	int profit = 0;
	for (int i = 1; i < sz; ++i)
	{
		if (prices[i] > prices[i - 1])
			profit += prices[i] - prices[i - 1];
	}
	return profit;
}

void testMaxProfit2()
{
}