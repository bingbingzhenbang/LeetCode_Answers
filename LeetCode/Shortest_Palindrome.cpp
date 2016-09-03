//Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.Find and return the shortest palindrome you can find by performing this transformation.
//
//For example :
//
//Given "aacecaaa", return "aaacecaaa".
//
//Given "abcd", return "dcbabcd".

#include <string>
#include <algorithm>

using namespace std;

string shortestPalindrome(string s)
{
	int n = s.size();
	string v(s.rbegin(), s.rend());
	int i = n;
	for (; i >= 1; --i)
	{
		if (s.substr(0, i) == v.substr(n - i))
			break;
	}
	for (; i < s.size(); i += 2)
		s = s[i] + s;
	return s;
}