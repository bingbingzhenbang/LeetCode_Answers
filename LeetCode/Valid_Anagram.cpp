//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//	For example,
//	s = "anagram", t = "nagaram", return true.
//	s = "rat", t = "car", return false. 
//
//Note:
//You may assume the string contains only lowercase alphabets.

#include <string>
#include <set>

using namespace std;

bool isAnagram(string s, string t) 
{
	if (s.size() != t.size())
		return false;
	else
	{
		multiset<char> ss(s.begin(), s.end()), ts(t.begin(), t.end());
		return ss == ts;
	}
}

void testIsAnagram()
{
	bool rt = isAnagram("anagram", "nagaram");
}