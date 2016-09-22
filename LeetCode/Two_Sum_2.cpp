//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.Please note that your returned answers(both index1 and index2) are not zero - based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers = { 2, 7, 11, 15 }, target = 9
//   Output : index1 = 1, index2 = 2

#include <vector>

using namespace std;

vector<int> twoSum2(vector<int>& numbers, int target)
{
	int i = 0, j = numbers.size() - 1;
	while (i < j)
	{
		int temp = numbers[i] + numbers[j];
		if (temp == target)
			return vector<int>({ i + 1, j + 1 });
		else if (temp < target)
			++i;
		else
			--j;
	}
	return vector<int>();
}