//Write a program to find the n - th ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
//Note that 1 is typically treated as an ugly number.
//
//Hint:
//
//The naive approach is to call isUgly for every number until you reach the nth one.Most numbers are not ugly.Try to focus your effort on generating only the ugly ones.
//An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
//The key is how to maintain the order of the ugly numbers.Try a similar approach of merging from three sorted lists : L1, L2, and L3.
//Assume you have Uk, the kth ugly number.Then Uk + 1 must be Min(L1 * 2, L2 * 3, L3 * 5).

#include <vector>
#include <algorithm>

using namespace std;

int nthUglyNumber(int n)
{
	vector<int> vec(n, 1);
	for (int i = 1; i < n; ++i)
	{
		auto itr1 = lower_bound(vec.begin(), vec.begin() + i, vec[i - 1] / 2 + 1);
		auto itr2 = lower_bound(vec.begin(), vec.begin() + i, vec[i - 1] / 3 + 1);
		auto itr3 = lower_bound(vec.begin(), vec.begin() + i, vec[i - 1] / 5 + 1);
		int a1 = *itr1, a2 = *itr2, a3 = *itr3;
		vec[i] = min(min(2 * a1, 3 * a2), 5 * a3);
	}
	return vec[n - 1];
}

int nthUglyNumber2(int n)
{
	vector<int> vec(n, 1);
	int index2 = 0, index3 = 0, index5 = 0;
	for (int i = 1; i < n; ++i)
	{
		vec[i] = min(min(2 * vec[index2], 3 * vec[index3]), 5 * vec[index5]);
		if (vec[i] == 2 * vec[index2])
			++index2;
		if (vec[i] == 3 * vec[index3])
			++index3;
		if (vec[i] == 5 * vec[index5])
			++index5;
	}
	return vec[n - 1];
}