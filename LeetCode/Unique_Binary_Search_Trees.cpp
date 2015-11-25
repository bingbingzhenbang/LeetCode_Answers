//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's. 
//1         3     3      2      1
//\ / / / \      \
//3     2     1      1   3      2
/// / \                 \
//2     1         2                 3

#include "ListNode.h"
#include <vector>

using namespace std;

int numTrees(int n)
{
	if (n < 0)
		return 0;
	else if (n == 0 || n == 1)
		return 1;
	else
	{
		//vector<int> vec(n, 0);
		//for (int i = 0; i < n; ++i)
		//{
		//	vec[i] = numTrees(i);
		//}
		//int sum = 0;
		//for (int i = 0; i < n; ++i)
		//{
		//	sum += vec[i] * vec[n - 1 - i];
		//}
		//return sum;
		vector<int> vec(n + 1, 0);
		vec[0] = vec[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			vec[i] = (double)vec[i - 1] * (2 * i - 1) * (2 * i) / (i * (i + 1));
		}
		return vec[n];
	}
}

void testNumTrees()
{
	int rt = numTrees(19);
}