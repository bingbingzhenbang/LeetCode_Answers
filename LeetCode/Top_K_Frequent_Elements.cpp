//Given a non - empty array of integers, return the k most frequent elements.
//
//For example,
//Given[1, 1, 1, 2, 2, 3] and k = 2, return[1, 2].
//
//Note:
//
//You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
	int size = nums.size();
	unordered_map<int, int> data_cnt;
	for (int i = 0; i < size; ++i)
		++data_cnt[nums[i]];
	priority_queue < pair<int, int> > Q;
	for (auto itr = data_cnt.begin(); itr != data_cnt.end(); ++itr)
		Q.push(pair<int, int>(itr->second, itr->first));
	vector<int> result(k, 0);
	for (int i = 0; i < k; ++i)
	{
		int temp = Q.top().second;
		result[i] = temp;
		Q.pop();
	}
	return result;
}
