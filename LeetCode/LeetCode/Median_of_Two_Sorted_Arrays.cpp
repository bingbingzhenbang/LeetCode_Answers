//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2 :
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is(2 + 3) / 2 = 2.5

#include <vector>
#include <algorithm>

using namespace std;

//Searching i in[0, m], to find an object `i` that:
//B[j - 1] <= A[i] and A[i - 1] <= B[j], (where j = (m + n + 1) / 2 - i)

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size(), n = nums2.size();
	if (m > n)
	{
		swap(m, n);
		swap(nums1, nums2);
	}
	int left = 0, right = m, half = (m + n + 1) / 2, i = 0, j = 0;
	while (left <= right)
	{
		i = (left + right) / 2;
		j = half - i;
		if ((i == 0 || j == n || nums1[i - 1] <= nums2[j]) && (i == m || j == 0 || nums2[j - 1] <= nums1[i]))
		{
			int max_left = 0, min_right = 0;
			if (i == 0)
				max_left = nums2[j - 1];
			else if (j == 0)
				max_left = nums1[i - 1];
			else
				max_left = max(nums1[i - 1], nums2[j - 1]);
			if (i == m)
				min_right = nums2[j];
			else if (j == n)
				min_right = nums1[i];
			else
				min_right = min(nums1[i], nums2[j]);
			if ((m + n) % 2 == 0)
				return ((double)max_left + (double)min_right) / 2;
			else
				return max_left;
		}
		else if (i > 0 && j < n && nums1[i - 1] > nums2[j])
			right = i - 1;
		else if (i < m && j > 0 && nums1[i] < nums2[j - 1])
			left = i + 1;
	}
	return -1;
}

void testFindMedianSortedArrays()
{
	vector<int> num1 = { 3, 5, 6, 7 }, num2 = { 1, 2, 4 };
	int rt = findMedianSortedArrays(num1, num2);
}