//Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ¡Ý s.If there isn't one, return 0 instead. 
//
//For example, given the array[2, 3, 1, 2, 4, 3] and s = 7,
//the subarray[4, 3] has the minimal length under the problem constraint.
//
//click to show more practice.
//
//More practice :
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

#include <vector>
#include <algorithm>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
	int size = nums.size();
	if (size == 0)
		return 0;
	int minLen = INT_MAX, left = 0, right = 0, currentSum = nums[0];
	while (right < size && left <= right)
	{
		if (currentSum < s)
		{
			++right;
			if (right < size)
				currentSum += nums[right];
		}
		else
		{
			minLen = min(minLen, right - left + 1);
			currentSum -= nums[left];
			++left;
		}
	}
	if (minLen == INT_MAX)
		return 0;
	else
		return minLen;
}