#include <vector>

using namespace std;

vector<int> decode(vector<int>& encoded) {
	int sz1 = encoded.size();
	int n = sz1 + 1;
	vector<int> ret(n);
	int total = 1;
	for (int i = 2; i <= n; ++i)
	{
		total ^= i;
	}
	int remain = encoded[1];
	for (int i = 3; i < sz1; i += 2)
	{
		remain ^= encoded[i];
	}
	ret[0] = total ^ remain;
	for (int i = 1; i < n; ++i)
	{
		ret[i] = ret[i - 1] ^ encoded[i - 1];
	}
	return ret;
}

void testDecode()
{
	//vector<int> encoded = { 6, 5, 4, 6 };
	//vector<int> ret = decode(encoded);

	vector<int> encoded = { 3, 1 };
	vector<int> ret = decode(encoded);
}
