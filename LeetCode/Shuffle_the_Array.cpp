#include <vector>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
	int N = nums.size();
	vector<int> ret(N);
	for (int i = 0; i < n; ++i)
	{
		ret[2 * i] = nums[i];
		ret[2 * i + 1] = nums[i + n];
	}
	return ret;
}