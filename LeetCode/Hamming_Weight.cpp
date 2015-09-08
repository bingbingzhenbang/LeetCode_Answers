//Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).
//
//	For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.

#include <iostream>
#include <cstdint>

using namespace std;

int hammingWeight(uint32_t n) 
{
	int index = 0, cnt = 0;
	for (; index < 32; ++index, n >>= 1)
	{
		cnt += (n & 1);
	}
	return cnt;
}

void testHammingWeight()
{
	int n;
	cin>>n;
	int rt = hammingWeight(n);
	cout<<rt<<endl;
}