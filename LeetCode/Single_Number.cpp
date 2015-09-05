//Given an array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

#include <iostream>

using namespace std;

int singleNumber(int* nums, int numsSize)
{
	int rt = nums[0], i;
	for (i = 1; i < numsSize; ++i)
		rt ^= nums[i];
	return rt;
}

void testsingleNumber()
{
	int arr[] = {1, 2, 3, 2, 1};
	cout<<singleNumber(arr, sizeof(arr)/sizeof(int))<<endl;
}