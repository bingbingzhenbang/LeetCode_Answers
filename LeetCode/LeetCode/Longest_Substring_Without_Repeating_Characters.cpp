//Given a string, find the length of the longest substring without repeating characters.For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
	vector<int> lastPosition(256, -1);
	int currentSubStringBefore = -1, max = 0, cnt = s.size();
	for (int i = 0; i < cnt; ++i)
	{
		if (lastPosition[s[i]] > currentSubStringBefore)
		{
			currentSubStringBefore = lastPosition[s[i]];
		}
		if (i - currentSubStringBefore > max)
		{
			max = i - currentSubStringBefore;
		}
		lastPosition[s[i]] = i;
	}
	return max;
}

void testLengthOfLongestSubstring()
{
	int rt = lengthOfLongestSubstring("abcabcbb");
}