//Given a non-negative number represented as an array of digits, plus one to the number.
//
//	The digits are stored such that the most significant digit is at the head of the list.

#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	int last = digits.size() - 1;
	while (last >= 0)
	{
		if (digits[last] < 9)
		{
			++digits[last];
			break;
		}
		else
			digits[last--] = 0;
	}
	if (digits[0] == 0)
	{
		vector<int> rt(digits.size() + 1, 0);
		rt[0] = 1;
		return rt;
	}
	else
		return digits;
}

void testPlusOne()
{
	int arr[] = {1};
	int sz = sizeof(arr)/sizeof(int);
	vector<int> nums(sz);
	for (int i = 0; i < sz; ++i)
		nums[i] = arr[i];
	vector<int> rt = plusOne(nums);
}