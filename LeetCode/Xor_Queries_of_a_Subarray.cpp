#include <vector>

using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
	int arrn = arr.size(), queryn = queries.size();
	vector<int> preXor(arrn), ret(queryn);
	preXor[0] = arr[0];
	for (int i = 1; i < arrn; ++i)
	{
		preXor[i] = preXor[i - 1] ^ arr[i];
	}
	for (int i = 0; i < queryn; ++i)
	{
		vector<int> &tmpquery = queries[i];
		int L = tmpquery[0], R = tmpquery[1];
		if (L == 0)
		{
			ret[i] = preXor[R];
		}
		else
		{
			ret[i] = preXor[L - 1] ^ preXor[R];
		}
	}
	return ret;
}