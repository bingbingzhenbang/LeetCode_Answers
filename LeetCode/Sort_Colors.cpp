//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue. 
//
//	Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 
//
//Note:
//You are not suppose to use the library's sort function for this problem. 

#include <vector>

using namespace std;

void sortColors(vector<int>& nums)
{
	int red_num = 0, white_num = 0, blue_num = 0;
	int sz = nums.size();
	for (int i = 0; i < sz; ++i)
	{
		if (nums[i] == 0)
			red_num++;
		if (nums[i] == 1)
			white_num++;
		if (nums[i] == 2)
			blue_num++;                
	}
	for (int i = 0; i < red_num; ++i)
		nums[i] = 0;
	for (int i = red_num; i < red_num + white_num; ++i)
		nums[i] = 1;
	for (int i = red_num + white_num; i < sz; ++i)
		nums[i] = 2;            
}