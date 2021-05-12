#include <vector>
#include <map>

using namespace std;

int numIdenticalPairs(vector<int>& nums) {
	map<int, int> count;
	int N = nums.size();
	for (int i = 0; i < N; ++i)
		++count[nums[i]];
	int ret = 0;
	for (auto itr = count.begin(); itr != count.end(); ++itr)
		ret += itr->second * (itr->second - 1) / 2;
	return ret;
}