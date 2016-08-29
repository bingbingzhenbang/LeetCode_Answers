//Shuffle a set of numbers without duplicates.
//
//Example:
//
//// Init an array with set 1, 2, and 3.
//int[] nums = { 1, 2, 3 };
//Solution solution = new Solution(nums);
//
//// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
//solution.shuffle();
//
//// Resets the array back to its original configuration [1,2,3].
//solution.reset();
//
//// Returns the random shuffling of array [1,2,3].
//solution.shuffle();

#include <vector>
#include <algorithm>

using namespace std;

class ShuffleSolution {
public:
	ShuffleSolution(vector<int> nums)
		: m_original(nums), m_data(nums)
	{
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
	{
		m_data = m_original;
		return m_data;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle()
	{
		random_shuffle(m_data.begin(), m_data.end());
		return m_data;
	}
private:
	vector<int> m_original;
	vector<int> m_data;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/