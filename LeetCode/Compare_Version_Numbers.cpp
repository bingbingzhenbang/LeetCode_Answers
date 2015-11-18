//Compare two version numbers version1 and version2.
//	If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//	You may assume that the version strings are non-empty and contain only digits and the . character.
//	The . character does not represent a decimal point and is used to separate number sequences.
//	For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
//	Here is an example of version numbers ordering:
//0.1 < 1.1 < 1.2 < 13.37

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> versionToNums(const string &version)
{
	const char dot('.');
	vector<int> nums;
	string::const_iterator iter_before = version.begin();
	string::const_iterator iter = find(iter_before, version.end(), dot);
	string str = string(iter_before, iter);
	while (!str.empty())
	{
		int temp = atoi(str.c_str());
		nums.push_back(temp);
		if (iter == version.end())
			break;
		iter_before = iter + 1;
		iter = std::find(iter_before, version.end(), dot);
		str = string(iter_before, iter);
	}
	return nums;
}

int compareVersion(string version1, string version2)
{
	vector<int> nums1 = versionToNums(version1), nums2 = versionToNums(version2);
	int i = 0;
	int sz1 = nums1.size(), sz2 = nums2.size();
	while (i < sz1 && i < sz2)
	{
		if (nums1[i] > nums2[i])
			return 1;
		else if (nums1[i] < nums2[i])
			return -1;
		else
			++i;
	}
	if (sz1 < sz2)
	{
		while (i < sz2)
		{
			if (nums2[i] > 0)
				return -1;
			else
				++i;
		}
	}
	else if (sz1 > sz2)
	{
		while (i < sz1)
		{
			if (nums1[i] > 0)
				return 1;
			else
				++i;
		}
	}
	return 0;
}

void testCompareVersion()
{
	string str1("1.0.0"), str2("1.0");
	int rt = compareVersion(str1, str2);
}