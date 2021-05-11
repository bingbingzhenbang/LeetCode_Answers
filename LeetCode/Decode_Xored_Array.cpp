#include <vector>

using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
	int sz1 = encoded.size();
	int sz2 = sz1 + 1;
	vector<int> ret(sz2, first);
	for (auto i = 1; i < sz2; ++i)
	{
		ret[i] = ret[i - 1] ^ encoded[i - 1];
	}
	return ret;
}