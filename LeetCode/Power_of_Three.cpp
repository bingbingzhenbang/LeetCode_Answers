//Given an integer, write a function to determine if it is a power of three.
//
//Follow up :
//Could you do it without using any loop / recursion ?

#include <cmath>

using namespace std;

bool isPowerOfThree(int n)
{
	int total = pow(3, 19);
	return (n > 0) && ((total % n) == 0);
}

void testIsPowerOfThree()
{
	bool rt = isPowerOfThree(27);
}