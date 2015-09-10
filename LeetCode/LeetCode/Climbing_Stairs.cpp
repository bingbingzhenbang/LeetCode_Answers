//You are climbing a stair case. It takes n steps to reach to the top.
//
//	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

#include <iostream>

using namespace std;

int climbStairs(int n)
{
	if (n == 1)
		return 1;
	int a = 1, b = 1, rt = 0;
	for (int i = 1; i < n; ++i)
	{
		rt = a + b;
		b = a;
		a = rt;
	}
	return rt;
}

void testClimbStairs()
{
	int a = 3;
	int rt = climbStairs(a);
}