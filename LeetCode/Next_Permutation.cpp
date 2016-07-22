//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//1, 2, 3 ¡ú 1, 3, 2
//3, 2, 1 ¡ú 1, 2, 3
//1, 1, 5 ¡ú 1, 5, 1

#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums)
{
	int size = nums.size();
	int i = size - 1;
	for (i; i > 0 && nums[i - 1] >= nums[i]; --i)
		;
	int tailbegin = i;
	if (tailbegin == 0)
	{
		reverse(nums.begin(), nums.end());
		return;
	}
	int j = size - 1;
	for (; j >= tailbegin && nums[j] <= nums[tailbegin - 1]; --j)
		;
	swap(nums[tailbegin - 1], nums[j]);
	reverse(nums.begin() + tailbegin, nums.end());
}