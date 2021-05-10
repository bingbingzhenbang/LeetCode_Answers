#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
	int sz = accounts.size();
	vector<int> wealth(sz, 0);
	for (int i = 0; i < sz; ++i)
	{
		vector<int> &account = accounts[i];
		wealth[i] = accumulate(account.begin(), account.end(), 0);
	}
	return *max_element(wealth.begin(), wealth.end());
}