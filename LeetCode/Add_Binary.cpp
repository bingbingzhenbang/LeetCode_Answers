//Given two binary strings, return their sum(also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
	int szA = a.size(), szB = b.size();
	if (szA == 0)
		return b;
	else if (szB == 0)
		return a;
	int sz = max(szA, szB), diff = abs(szA - szB);
	if (szA > szB)
		b.insert(b.begin(), diff, '0');
	else if (szA < szB)
		a.insert(a.begin(), diff, '0');
	string rt;
	char carry = '0';
	for (int i = sz - 1; i >= 0; --i)
	{
		char chA = a[i], chB = b[i];
		if (carry == '1')
		{
			if (chA == '1' && chB == '1')
			{
				rt.push_back('1');
				carry = '1';
			}
			else if (chA == '1' || chB == '1')
			{
				rt.push_back('0');
				carry = '1';
			}
			else
			{
				rt.push_back('1');
				carry = '0';
			}
		}
		else
		{
			if (chA == '1' && chB == '1')
			{
				rt.push_back('0');
				carry = '1';
			}
			else if (chA == '1' || chB == '1')
			{
				rt.push_back('1');
				carry = '0';
			}
			else
			{
				rt.push_back('0');
				carry = '0';
			}
		}
	}
	if (carry == '1')
		rt.push_back('1');
	reverse(rt.begin(), rt.end());
	return rt;
}

void testAddBinary()
{
	string rt = addBinary("10", "100");
}