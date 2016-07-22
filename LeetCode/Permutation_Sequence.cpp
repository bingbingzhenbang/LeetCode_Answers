//The set[1, 2, 3, бн, n] contains a total of n!unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence(ie, for n = 3) :
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//Given n and k, return the kth permutation sequence.
//
//Note: Given n will be between 1 and 9 inclusive.

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string getPermutation1(int n, int k)
{
	string str;
	for (int i = 1; i <= n; ++i)
		str += to_string(i);
	for (int t = 1; t < k; ++t)
	{
		int i = n - 1;
		for (; i > 0 && str[i - 1] > str[i]; --i)
			;
		int tailbegin = i;
		if (tailbegin == 0)
		{
			reverse(str.begin(), str.end());
			return str;
		}
		int j = n - 1;
		for (; j >= tailbegin && str[j] < str[tailbegin - 1]; --j)
			;
		swap(str[tailbegin - 1], str[j]);
		reverse(str.begin() + tailbegin, str.end());
	}
	return str;
}

string getPermutation(int n, int k)
{
	vector<int> factorial(10, 1);
	for (int i = 1; i <= 9; ++i)
		factorial[i] = i * factorial[i - 1];
	vector<char> numbers(9, '1');
	for (int i = 1; i < 9; ++i)
		numbers[i] += i;
	string result;
	while (n > 0)
	{
		int index = (k - 1) / factorial[n - 1];
		result.push_back(numbers[index]);
		numbers.erase(numbers.begin() + index);
		k -= index * factorial[n - 1];
		--n;
	}
	return result;
}

void testGetPermutation()
{
	string rt = getPermutation(10, 10100);
}