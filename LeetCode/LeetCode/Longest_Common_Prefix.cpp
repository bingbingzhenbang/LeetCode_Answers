//Write a function to find the longest common prefix string amongst an array of strings

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
	int sz = strs.size();
	if (sz == 0)
		return string();
	else if (sz == 1)
		return strs[0];
	string prefix = strs[0];
	for (int i = 1; i < sz; ++i)
	{
		string &temp = strs[i];
		int prefixSZ = prefix.size(), tempSZ = temp.size();
		if (prefixSZ == 0 || tempSZ == 0)
			return string();
		int len = min(prefixSZ, tempSZ);
		int j = 0;
		for (; j < len; ++j)
		{
			if (prefix[j] != temp[j])
				break;
		}
		prefix = prefix.substr(0, j);
	}
	return prefix;
}

void testLongestCommonPrefix()
{
	vector<string> strs = { "a", "b" };
	string rt = longestCommonPrefix(strs);
}