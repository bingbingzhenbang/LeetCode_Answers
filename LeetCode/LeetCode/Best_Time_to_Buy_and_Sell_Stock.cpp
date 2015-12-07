//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
	int sz = prices.size();
	if (sz == 0 || sz == 1)
		return 0;
	int profit = 0, low = prices[0];
	for (int i = 1; i < sz; ++i)
	{
		if (prices[i] < low)
			low = prices[i];
		else if (prices[i] - low > profit)
			profit = prices[i] - low;
	}
	return profit;
}

void testMaxProfit()
{
}