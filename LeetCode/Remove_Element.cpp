//Given an array and a value, remove all instances of that value in place and return the new length. 
//
//	The order of elements can be changed. It doesn't matter what you leave beyond the new length. 

#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int sz = nums.size();
	int space_beg = -1, space_end = -1;
	if (sz == 0)
		return 0;
	if (sz == 1)
	{
		if (nums[0] == val)
		{
			nums[0] = 0;
			return 0;
		}
		else
			return 1;
	}
	for (int i = 0; i < sz; ++i)
	{
		if (nums[i] == val)
		{
			space_beg = i;
			break;
		}
	}
	for (int i = space_beg + 1; i < sz; ++i)
	{
		if (nums[i] != val)
		{
			space_end = i - 1;
			break;
		}
	}
	if (space_beg == -1 || space_end == -1)
		return 0;
	else
	{
		for (int i = space_end + 1; i < sz;)
		{
			if (nums[i] != val)
			{
				nums[space_beg] = nums[i];
				++space_beg;
				++space_end;
				++i;
			}
			else
			{
				++space_end;
				i = space_end + 1;
			}
		}
		for (int i = space_beg; i <=space_end; ++i)
			nums[i] = 0;
		return space_beg;
	}
}

void testRemoveElement()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(3);
	removeElement(nums, 5);
}