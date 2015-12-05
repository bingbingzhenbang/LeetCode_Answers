//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.The number of elements initialized in nums1 and nums2 are m and n respectively.

#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = 0, j = 0, currentSZ = m, totalSZ = m + n;
	for (; currentSZ < totalSZ; )
	{
		if (nums2[i] <= nums1[j])
		{
			int before_i = i;
			for (; i < n && nums2[i] <= nums1[j]; ++i)
				;
			int insertSZ = i - before_i;
			for (int k = currentSZ - 1; k >= j; --k)
				nums1[k + insertSZ] = nums1[k];
			currentSZ += insertSZ;
			for (int k = before_i; k < i; ++k, ++j)
				nums1[j] = nums2[k];
		}
		else
		{
			for (; j < currentSZ && nums1[j] < nums2[i]; ++j)
				;
			if (j == currentSZ)
			{
				for (int k = i; k < n; ++k, ++j)
					nums1[j] = nums2[k];
				currentSZ = totalSZ;
			}
		}
	}
}