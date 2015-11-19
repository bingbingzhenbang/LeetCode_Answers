//Given an index k, return the kth row of the Pascal's triangle.
//
//	For example, given k = 3,
//	Return [1,3,3,1]. 
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space?

#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
	if (rowIndex < 0)
		return vector<int>();
	vector<int> result(rowIndex + 1, 0);
	result[0] = 1;
	for (int row = 1; row <= rowIndex; ++row)
	{
		for (int j = row; j >= 1; --j)
			result[j] += result[j - 1];
	}
	return result;
}

void testGetRow()
{
	vector<int> rt = getRow(5);
}
