//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//
//Define a pair(u, v) which consists of one element from the first array and one element from the second array.
//
//Find the k pairs(u1, v1), (u2, v2) ...(uk, vk) with the smallest sums.
//
//Example 1:
//
//Given nums1 = [1, 7, 11], nums2 = [2, 4, 6], k = 3
//
//Return : [1, 2], [1, 4], [1, 6]
//
//		 The first 3 pairs are returned from the sequence :
//[1, 2], [1, 4], [1, 6], [7, 2], [7, 4], [11, 2], [7, 6], [11, 4], [11, 6]
//
//
//
//Example 2 :
//
//Given nums1 = [1, 1, 2], nums2 = [1, 2, 3], k = 2
//
//Return : [1, 1], [1, 1]
//
//		 The first 2 pairs are returned from the sequence :
//[1, 1], [1, 1], [1, 2], [2, 1], [1, 2], [2, 2], [1, 3], [1, 3], [2, 3]
//
//
//
//Example 3 :
//
//Given nums1 = [1, 2], nums2 = [3], k = 3
//
//Return : [1, 3], [2, 3]
//
//		 All possible pairs are returned from the sequence :
//[1, 3], [2, 3]

#include <vector>
#include <map>

using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
	int size1 = nums1.size(), size2 = nums2.size();
	if (size1 == 0 || size2 == 0)
		return vector<pair<int, int>>();
	map<int, vector< pair<int, int> > > sumIndexes;
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
			sumIndexes[nums1[i] + nums2[j]].push_back(pair<int, int>(nums1[i], nums2[j]));
	}
	vector<pair<int, int>> result;
	map<int, vector< pair<int, int> > >::iterator itr = sumIndexes.begin();
	for (int cnt = 0; cnt < k && itr != sumIndexes.end(); ++itr)
	{
		for (auto vecitr = itr->second.begin(); cnt < k && vecitr != itr->second.end(); ++cnt, ++vecitr)
			result.push_back(pair<int, int>(vecitr->first, vecitr->second));
	}
	return result;
}
