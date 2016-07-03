//Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once.You must make sure your result is the smallest in lexicographical order among all possible results.
//
//Example:
//
//
//Given "bcabc"
//Return "abc"
//
//Given "cbacdcbc"
//Return "acdb"

#include <string>
#include <vector>
#include <stack>

using namespace std;

string removeDuplicateLetters(string s)
{
	int size = s.size();
	vector<char> letterVec;
	vector<int> letterCnt(26, 0), letterIn(26, 0);
	for (int i = 0; i < size; ++i)
		++letterCnt[s[i] - 'a'];
	for (int i = 0; i < size; ++i)
	{
		int letterIndex = s[i] - 'a';
		if (letterIn[letterIndex])
		{
			--letterCnt[letterIndex];
			continue;
		}
		while (!letterVec.empty() && s[i] < letterVec.back() && letterCnt[letterVec.back() - 'a'] > 0)
		{
			letterIn[letterVec.back() - 'a'] = 0;
			letterVec.pop_back();
		}
		letterVec.push_back(s[i]);
		--letterCnt[letterIndex];
		letterIn[letterIndex] = 1;
	}
	return string(letterVec.begin(), letterVec.end());
}