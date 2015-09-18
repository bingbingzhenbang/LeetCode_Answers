//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321 

#include <stack>
#include <limits>

using namespace std;

int reverse(int x)
{
	if (x == 0)
		return 0;
	bool isNegative = (x < 0);
	if (isNegative)
		x = -x;
	int rt = 0, bit = 1;
	int int_max = numeric_limits<int>::max();
	while (x > 0)
	{		
		if ((double)int_max / 10 <= (double)rt)
			return 0;
		else
		{
			rt *= 10;
			rt += x % 10;
			x /= 10;
		}
	}
	if (isNegative)
		rt = -rt;
	return rt;
}

void testReverse()
{
	int rt = reverse(-123456);
}