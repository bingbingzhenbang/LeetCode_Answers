//Given a list of non negative integers, arrange them such that they form the largest number.
//
//	For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool strLarger(int a, int b)
{
	string s_a(to_string(a)), s_b(to_string(b));
	string str1 = s_a + s_b;
	string str2 = s_b + s_a;
	return str1 > str2;
}

string largestNumber(vector<int>& nums)
{
	sort(nums.begin(), nums.end(), strLarger);
	if (nums[0] == 0)
		return string("0");
	string result;
	int sz = nums.size();
	for (int i = 0; i < sz; ++i)
		result += to_string(nums[i]);
	return result;
}

void testLargestNumber()
{
	//int arr[] = {3, 30, 34, 5, 9};
	int arr[] = {0, 1, 0};
	int sz = sizeof(arr)/sizeof(int);
	vector<int> nums(sz);
	for (int i = 0; i < sz; ++i)
		nums[i] = arr[i];
	string str = largestNumber(nums);
}