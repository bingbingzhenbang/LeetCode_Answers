#include <vector>

using namespace std;

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
	int N = queries.size();
	vector<int> ret(N, 0);
	int M = points.size();
	for (int i = 0; i < N; ++i)
	{
		vector<int> &circle = queries[i];
		int rsqr = circle[2] * circle[2];
		for (int j = 0; j < M; ++j)
		{
			vector<int> &point = points[j];
			int disx = point[0] - circle[0];
			int disy = point[1] - circle[1];
			if (disx *disx + disy * disy <= rsqr)
				++ret[i];
		}
	}
	return ret;
}