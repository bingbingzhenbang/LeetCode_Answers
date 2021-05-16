#include <map>
#include <vector>

using namespace std;

class SparseVector {
public:
	map<int, int> Values;
	SparseVector(vector<int> &nums) {
		int N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			if (nums[i])
				Values[i] = nums[i];
		}
	}

	// Return the dotProduct of two sparse vectors
	int dotProduct(SparseVector& vec) {
		int ret = 0;
		for (auto itr1 = vec.Values.begin(); itr1 != vec.Values.end(); ++itr1)
		{
			auto itr2 = Values.find(itr1->first);
			if (itr2 != Values.end())
				ret += itr1->second * itr2->second;
		}
		return ret;
	}
};