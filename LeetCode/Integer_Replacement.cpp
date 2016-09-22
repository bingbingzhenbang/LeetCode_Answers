//Given a positive integer n and you can do operations as follow :
//
//If n is even, replace n with n / 2.
//If n is odd, you can replace n with either n + 1 or n - 1.
//What is the minimum number of replacements needed for n to become 1 ?
//
//Example 1 :
//
//Input :
//	  8
//
//  Output :
//		 3
//
//	 Explanation :
//				 8 -> 4 -> 2 -> 1
//				 Example 2 :
//
//			 Input :
//				   7
//
//			   Output :
//					  4
//
//				  Explanation :
//							  7 -> 8 -> 4 -> 2 -> 1
//							  or
//							  7 -> 6 -> 3 -> 2 -> 1

int integerReplacement(int n)
{
	unsigned int un = n;
	int cnt = 0;
	while (un > 3)
	{
		if (un % 2)
		{
			if (un & 2)
				++un;
			else
				--un;
		}
		else
			un >>= 1;
		++cnt;
	}
	return cnt + un - 1;
}