//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].
//
//Note:
//Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k)
{
	int n = nums.size();
	if (n == 0)
		return;
	k = k % n;
	if (k == 0)
		return;
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

void testRotateArray()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	rotate(nums, 3);
}