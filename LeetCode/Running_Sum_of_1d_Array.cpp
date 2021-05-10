#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
	int sz = nums.size();
	vector<int> ret(sz, 0);
	for (int i = 0; i < sz; ++i)
	{
		if (i == 0)
			ret[i] = nums[i];
		else
			ret[i] = ret[i - 1] + nums[i];
	}
	return ret;
}
