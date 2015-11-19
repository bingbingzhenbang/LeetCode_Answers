//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//	For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 

#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> result;
	size_t sz = nums.size();
	if (sz == 0)
		return result;
	string arrow = "->";
	for (size_t i = 0; i < sz;)
	{
		size_t j = i + 1;
		for (; j < sz && nums[j] == nums[j - 1] + 1; ++j)
			;
		if (j == i + 1)
		{
			string str = to_string(nums[i]);
			result.push_back(str);
		}
		else
		{
			string str = to_string(nums[i]);
			str.append(arrow);
			str.append(to_string(nums[j - 1]));
			result.push_back(str);
		}
		i = j;
	}
	return result;
}

void testSummaryRanges()
{
	int arr[] = {1, 2, 3, 5, 7, 8, 9, 11};
	int sz = sizeof(arr)/sizeof(int);
	vector<int> nums(sz);
	for (int i = 0; i < sz; ++i)
		nums[i] = arr[i];
	vector<string> rt = summaryRanges(nums);
}