//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//	For example:
//1 -> A
//	2 -> B
//	3 -> C
//	...
//	26 -> Z
//	27 -> AA
//	28 -> AB 
//

#include <string>

using namespace std;

string convertToTitle(int n)
{
	string temp;
	while (n > 0)
	{
		int r = n % 26;
		int bit = r ? r : 26;
		char ch = 'A' - 1 + bit;
		temp += ch;
		n = (n - bit)/26;
	}
	string result(temp.rbegin(), temp.rend());
	return result;
}

void testConvertToTitle()
{
	string rt = convertToTitle(26);
}