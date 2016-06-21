//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].
//
//
//
//UPDATE(2016 / 2 / 13) :
//The return format had been changed to zero - based indices.Please read the above updated description carefully.

#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> num2Pos;
	int size = nums.size();
	for (int i = 0; i < size; ++i)
	{
		unordered_map<int, int>::iterator itr = num2Pos.find(target - nums[i]);
		if (itr == num2Pos.end())
			num2Pos[nums[i]] = i;
		else
			return vector<int>({ i, itr->second });
	}
	return vector<int>();
}