//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.

#include <iostream>

using namespace std;

int trailingZeroes(int n)
{
	int base = 5, cnt = 0;
	while (n >= base)
	{
		n /= base;
		cnt += n;
	}
	return cnt;
}

void testTrailingZeroes()
{
	int n;
	cin>>n;
	int rt = trailingZeroes(n);
	cout<<rt<<endl;
}