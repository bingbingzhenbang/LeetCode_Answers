//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//	For example,
//	Given sorted array nums = [1,1,1,2,2,3], 
//
//	Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length. 

#include <vector>

using namespace std;

int removeDuplicates2(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	size_t cnt = 0, i = 0, j = i + 1;
	size_t sz = nums.size();
	for (; i < sz; )
	{
		j = i + 1;
		for (; j < sz && nums[i] == nums[j]; ++j)
			;
		if (j - i > 2)
		{
			for (size_t k = j; k < sz; ++k)
				nums[k - j + i + 2] = nums[k];
			cnt += 2;
			if (j < sz)
			{
				sz -= j - i - 2;
				i += 2;
			}
			else
				return cnt;
		}
		else if (j - i == 2)
		{
			cnt += 2;
			i += 2;
		}
		else
		{
			++i;
			++cnt;
		}
	}
	return cnt;
}

void testRemoveDuplicates2()
{
	int arr[] = {1,2,2,2,3,3};
	int sz = sizeof(arr)/sizeof(int);
	vector<int> nums(sz);
	for (int i = 0; i < sz; ++i)
		nums[i] = arr[i];
	int rt = removeDuplicates2(nums);
}