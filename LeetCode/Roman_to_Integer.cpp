//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <string>

using namespace std;

inline int char2num(char ch)
{
	switch (ch)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return 0;
	}
	return 0;
}

int romanToInt(string s)
{
	int cnt = s.size();
	if (cnt == 0)
		return 0;
	int result = char2num(s[0]);
	for (int i = 1; i < cnt; ++i)
	{
		if (char2num(s[i-1]) < char2num(s[i]))
		{
			result += char2num(s[i]) - 2 * char2num(s[i - 1]);
		}
		else
		{
			result += char2num(s[i]);
		}
	}
	return result;
}

void testRomanToInt()
{

}