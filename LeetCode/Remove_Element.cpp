//Given an array and a value, remove all instances of that value in place and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.
//
//Example:
//Given input array nums = [3, 2, 2, 3], val = 3
//
//Your function should return length = 2, with the first two elements of nums being 2.
//
//Hint :
//	 1.Try two pointers.
//	 2.Did you use the property of "the order of elements can be changed" ?
//	 3.What happens when the elements to remove are rare ?

#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int size = nums.size();
	if (size == 0)
		return 0;
	sort(nums.begin(), nums.end());
	vector<int>::iterator itr = find(nums.begin(), nums.end(), val);
	if (itr == nums.end())
		return size;
	int cnt = count(nums.begin(), nums.end(), val);
	int startIndex = itr - nums.begin();
	for (int i = startIndex; i < size - cnt; ++i)
		nums[i] = nums[i + cnt];
	return size - cnt;
}

void testRemoveElement()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(3);
	removeElement(nums, 3);
}