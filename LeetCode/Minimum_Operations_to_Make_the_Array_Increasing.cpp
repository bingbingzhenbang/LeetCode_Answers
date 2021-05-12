#include <vector>

using namespace std;

int minOperations(vector<int>& nums) {
	int N = nums.size(), ret = 0;
	for (int i = 1; i < N; ++i)
	{
		if (nums[i] <= nums[i - 1])
		{
			int tmp = nums[i - 1] + 1 - nums[i];
			nums[i] += tmp;
			ret += tmp;
		}
	}
	return ret;
}