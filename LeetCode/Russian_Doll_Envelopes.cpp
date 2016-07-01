//You have a number of envelopes with widths and heights given as a pair of integers(w, h).One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
//What is the maximum number of envelopes can you Russian doll ? (put one inside other)
//
//Example :
//		Given envelopes = [[5, 4], [6, 4], [6, 7], [2, 3]], the maximum number of envelopes you can Russian doll is 3 ([2, 3] = > [5, 4] = > [6, 7]).

#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
	int size = envelopes.size();
	if (size == 0)
		return 0;
	sort(envelopes.begin(), envelopes.end());
	vector<int> dp(size, 1);
	int ret = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ret = max(ret, dp[i]);
	}
	return ret;
}