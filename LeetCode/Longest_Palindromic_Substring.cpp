//Given a string S, find the longest palindromic substring in S.You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

#include <vector>
#include <string>

using namespace std;

//enum LCSDirection
//{
//	LCS_left = 1,
//	LCS_top = 2,
//	LCS_lefttop = 3,
//};
//
//string LCS(string &s1, string &s2)
//{
//	int m = s1.size(), n = s2.size();
//	vector<vector <int> > c(m + 1, vector<int>(n + 1, 0));
//	vector<vector <int> > d(m, vector<int>(n, 0));
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			if (s1[i] == s2[j])
//			{
//				c[i + 1][j + 1] = c[i][j] + 1;
//				d[i][j] = LCS_lefttop;
//			}
//			else
//			{
//				if (c[i + 1][j] > c[i][j + 1])
//				{
//					c[i + 1][j + 1] = c[i + 1][j];
//					d[i][j] = LCS_left;
//				}
//				else
//				{
//					c[i + 1][j + 1] = c[i][j + 1];
//					d[i][j] = LCS_top;
//				}
//			}
//		}
//	}
//	int LCSlen = c[m][n];
//	vector<char> charvec(LCSlen, 0);
//	for (int k = LCSlen - 1, i = m - 1, j = n - 1; k >= 0 && i >= 0 && j >= 0;)
//	{
//		switch (d[i][j])
//		{
//		case LCS_lefttop:
//		{
//							charvec[k] = s1[i];
//							--i;
//							--j;
//							--k;
//		}
//			break;
//		case LCS_left:
//		{
//						 --j;
//		}
//			break;
//		case LCS_top:
//		{
//						--i;
//		}
//			break;
//		}
//	}
//	return string(charvec.begin(), charvec.end());
//}
//
//string longestPalindrome(string s)
//{
//	string s1(s.rbegin(), s.rend());
//	return LCS(s, s1);
//}

string longestPalindrome(string s)
{
	int size = s.size();
	if (size <= 1)
		return s;
	int start = 0, maxLen = 1;
	for (int i = 0; i < size;)
	{
		int jstart = i, jend = i;
		for (; jend < size - 1 && s[jend] == s[jend + 1]; ++jend)
			;
		i = jend + 1;
		for (; jstart > 0 && jend < size - 1 && s[jstart - 1] == s[jend + 1]; --jstart, ++jend)
			;
		int newLen = jend - jstart + 1;
		if (newLen > maxLen)
		{
			maxLen = newLen;
			start = jstart;
		}
	}
	return s.substr(start, maxLen);
}

void testLongestPalindrome()
{
	string str = "aaaabaaa";
	string rt = longestPalindrome(str);
}
