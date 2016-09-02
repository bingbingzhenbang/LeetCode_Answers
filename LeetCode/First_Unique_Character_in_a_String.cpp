//Given a string, find the first non - repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples:
//
//s = "leetcode"
//return 0.
//
//s = "loveleetcode",
//return 2.
//Note: You may assume the string contain only lowercase letters.

#include <string>
#include <map>

using namespace std;

int firstUniqChar(string s)
{
	map<char, int> ch2cnt;
	int sz = s.size();
	for (int i = 0; i < sz; ++i)
		++ch2cnt[s[i]];
	for (int i = 0; i < sz; ++i)
	{
		if (ch2cnt[s[i]] == 1)
			return i;
	}
	return -1;
}