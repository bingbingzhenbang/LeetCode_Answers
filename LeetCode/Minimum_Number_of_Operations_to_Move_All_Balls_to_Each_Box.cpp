#include <vector>
#include <numeric>

using namespace std;

vector<int> minOperations(string boxes) {
	int N = boxes.size();
	vector<vector<int>> dis(N, vector<int>(N, 0));
	for (int i = 0; i < N - 1; ++i)
	{
		bool need = (boxes[i] == '1');
		for (int j = i + 1; j < N; ++j)
		{
			int tmp = j - i;
			if (boxes[j] == '1')
			{
				dis[i][j] += tmp;
			}
			if (need)
				dis[j][i] += tmp;
		}
	}
	vector<int> ret(N, 0);
	for (int i = 0; i < N; ++i)
	{
		ret[i] = accumulate(dis[i].begin(), dis[i].end(), 0);
	}
	return ret;
}

vector<int> minOperations2(string boxes) {
	int N = boxes.size(), left = 0, right = 0, steps = 0;
	for (int i = 1; i < N; ++i)
	{
		if (boxes[i] == '1')
		{
			++right;
			steps += i;
		}
	}
	if (boxes[0] == '1')
		++left;

	vector<int> ret(N, 0);
	ret[0] = steps;
	for (int i = 1; i < N; ++i)
	{
		steps += (left - right);
		ret[i] = steps;
		if (boxes[i] == '1')
		{
			++left;
			--right;
		}
	}
	return ret;
}