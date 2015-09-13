//Given an integer, write a function to determine if it is a power of two. 

bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	int low = n & (-n);
	return n == low;
}

void testIsPowerOfTwo()
{
	bool rt = isPowerOfTwo(32);
}