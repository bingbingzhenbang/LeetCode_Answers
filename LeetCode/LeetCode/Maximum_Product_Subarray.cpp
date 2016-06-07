//Find the contiguous subarray within an array(containing at least one number) which has the largest product.
//
//For example, given the array[2, 3, -2, 4],
//the contiguous subarray[2, 3] has the largest product = 6.

#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums)
{
	int size = nums.size();
	if (size == 0)
		return 0;
	int max_product = nums[0], min_product = nums[0], max_res = nums[0];
	for (int i = 1; i < size; ++i)
	{
		int d = nums[i];
		if (d >= 0)
		{
			max_product = max(max_product * d, d);
			min_product = min(min_product * d, d);
		}
		else
		{
			int temp = max_product;
			max_product = max(min_product * d, d);
			min_product = min(temp * d, d);
		}
		max_res = max(max_res, max_product);
	}
	return max_res;
}

void testMaxProduct()
{
	vector<int> nums = { 2, -1, 3, 0, 5, -2, 6 };
	int rt = maxProduct(nums);
}