//Reverse bits of a given 32 bits unsigned integer.
//
//	For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//
//	Follow up:
//If this function is called many times, how would you optimize it? 
//

#include <cstdint>

uint32_t reverseBits(uint32_t n)
{
	uint32_t rt = 0, cnt = 0;
	while (cnt < 32)
	{
		rt *= 2;
		rt += n % 2;
		n /= 2;
		++cnt;
	}
	return rt;
}

void testReverseBits()
{
	uint32_t rt = reverseBits(43261596);
}