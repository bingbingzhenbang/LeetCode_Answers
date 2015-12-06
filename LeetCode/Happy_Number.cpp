//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process : Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example : 19 is a happy number
//		  1^2 + 9^2 = 82
//		  8^2 + 2^2 = 68
//		  6^2 + 8^2 = 100
//		  1^2 + 0^2 + 0^2 = 1

#include <unordered_set>

using namespace std;

bool isHappy(int n)
{
	if (n <= 0)
		return false;
	if (n == 1)
		return true;
	unordered_set<int> showedNums;
	showedNums.insert(n);
	while (true)
	{
		int s = 0;
		while (n)
		{
			int bit = n % 10;
			s += bit * bit;
			n /= 10;
		}
		if (s == 1)
			return true;
		else
		{
			if (showedNums.find(s) != showedNums.end())
				return false;
			else
			{
				showedNums.insert(s);
				n = s;
			}
		}
	}
	return false;
}

void testIsHappy()
{
	bool rt = isHappy(19);
}