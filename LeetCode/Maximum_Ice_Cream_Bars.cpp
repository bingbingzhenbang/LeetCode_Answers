#include <vector>
#include <algorithm>

using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
	sort(costs.begin(), costs.end());
	int N = costs.size(), ret = 0;
	for (int i = 0; i < N; ++i)
	{
		if (coins >= costs[i])
		{
			++ret;
			coins -= costs[i];
		}
		else
			break;
	}
	return ret;
}