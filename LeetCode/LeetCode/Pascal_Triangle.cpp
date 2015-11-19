//Given numRows, generate the first numRows of Pascal's triangle.
//
//	For example, given numRows = 5,
//	Return 
//	[
//		[1],
//		[1,1],
//		[1,2,1],
//		[1,3,3,1],
//		[1,4,6,4,1]
//	]

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> all_result;
	if (numRows >= 1)
	{
		vector<int> first_line(1, 1);
		all_result.push_back(first_line);
		for (int row = 1; row < numRows; ++row)
		{
			vector<int> &last_row = all_result[row - 1];
			vector<int> new_line(last_row.size() + 1, 1);
			for (int j = 1; j < new_line.size() - 1; ++j)
			{
				new_line[j] = last_row[j - 1] + last_row[j];
			}
			all_result.push_back(new_line);
		}
	}
	return all_result;
}

void testGenerate()
{
	vector<vector<int>> rt = generate(5);
	for (size_t i = 0; i < rt.size(); ++i)
	{
		for (size_t j = 0; j < rt[i].size(); ++j)
		{
			cout<<rt[i][j]<<" ";
		}
		cout<<endl;
	}
}