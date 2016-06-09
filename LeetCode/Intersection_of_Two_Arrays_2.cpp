//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2, 2].
//
//Note :
//
//	 Each element in the result should appear as many times as it shows in both arrays.
//	 The result can be in any order.
//
//
//	 Follow up :
//
//What if the given array is already sorted ? How would you optimize your algorithm ?
//What if nums1's size is small compared to nums2's size ? Which algorithm is better ?
//What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once ?

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
	int sz1 = nums1.size(), sz2 = nums2.size();
	if (sz1 == 0 || sz2 == 0)
		return vector<int>();
	map<int, int> num_cnt1, num_cnt2;
	for (int i = 0; i < sz1; ++i)
		++num_cnt1[nums1[i]];
	for (int i = 0; i < sz2; ++i)
		++num_cnt2[nums2[i]];
	if (num_cnt1.rbegin()->first < num_cnt2.begin()->first || num_cnt1.begin()->first > num_cnt2.rbegin()->first)
		return vector<int>();
	vector<int> result;
	for (auto itr1 = num_cnt1.begin(), itr2 = num_cnt2.begin(); itr1 != num_cnt1.end() && itr2 != num_cnt2.end();)
	{
		if (itr1->first == itr2->first)
		{
			int cnt = min(itr1->second, itr2->second);
			for (int j = 0; j < cnt; ++j)
				result.push_back(itr1->first);
			++itr1;
			++itr2;
		}
		else if (itr1->first < itr2->first)
			++itr1;
		else
			++itr2;
	}
	return result;
}

void testIntersect()
{
	vector<int> nums1 = { 1 };
	vector<int> nums2 = { 1, 2 };
	vector<int> rt = intersect(nums1, nums2);
}