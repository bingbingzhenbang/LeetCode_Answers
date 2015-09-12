//Related to question Excel Sheet Column Title
//
//	Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//	For example:
//A -> 1
//	B -> 2
//	C -> 3
//	...
//	Z -> 26
//	AA -> 27
//	AB -> 28 

#include <string>

using namespace std;

int titleToNumber(string s) 
{
	int rt = 0, sz = s.size(), bit = 1;
	char start = 'A';
	for (int i = sz - 1; i >=0; --i)
	{
		rt += (s[i] - start + 1) * bit;
		bit *= 26;
	}
	return rt;
}

void testTitleToNumber()
{
	int rt = titleToNumber("AB");
}