//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should :
//
//
//Return true if there exists i, j, k
//such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n - 1 else return false.
//
//
//Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//Examples:
//Given[1, 2, 3, 4, 5],
//return true.
//
//Given[5, 4, 3, 2, 1],
//return false.

#include <vector>

using namespace std;

bool increasingTriplet(vector<int>& nums)
{
	int size = nums.size();
	if (size < 3)
		return false;
	int c1 = INT_MAX, c2 = INT_MAX;
	for (int i = 0; i < size; ++i)
	{
		int x = nums[i];
		if (x <= c1)
			c1 = x;
		else if (x <= c2)
			c2 = x;
		else
			return true;
	}
	return false;
}

void testIncreasingTriplet()
{
	vector<int> nums = { 5, 6, 1, 7 };
	bool rt = increasingTriplet(nums);
}