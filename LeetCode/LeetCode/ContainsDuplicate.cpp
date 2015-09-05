//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	set<int> elements;
	size_t vec_sz = nums.size();
	for (size_t i = 0; i < vec_sz; ++i)
	{
		if (elements.insert(nums[i]).second == false)
			return true;
	}
	return false;
}

void testContainsDuplicate()
{
	int arr[] = {1, 2, 3, 2, 1};
	vector<int> nums;
	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i)
		nums.push_back(arr[i]);

	bool rt = containsDuplicate(nums);
	if (rt)
		cout<<"containsDuplicate!"<<endl;
	else
		cout<<"not containsDuplicate!"<<endl;
}