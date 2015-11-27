//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//You may assume both s and t have the same length.

#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t)
{
	int sz = s.size();
	unordered_map<char, char> s2t, t2s;
	for (int i = 0; i < sz; ++i)
	{
		unordered_map<char, char>::iterator itr1 = s2t.find(s[i]);
		unordered_map<char, char>::iterator itr2 = t2s.find(t[i]);
		if (itr1 == s2t.end() && itr2 == t2s.end())
		{
			s2t[s[i]] = t[i];
			t2s[t[i]] = s[i];
		}
		else if (itr1 != s2t.end() && itr2 != t2s.end())
		{
			if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i])
				return false;
		}
		else
			return false;
	}
	return true;
}

void testIsIsomorphic()
{
	//bool rt = isIsomorphic("egg", "odd");
	bool rt = isIsomorphic("aa", "ab");
}
