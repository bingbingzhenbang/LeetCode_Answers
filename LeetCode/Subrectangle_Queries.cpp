#include <vector>

using namespace std;

class SubrectangleQueries {
private:
	int Row = 0;
	int Col = 0;
	vector<vector<int>> Values;
public:
	SubrectangleQueries(vector<vector<int>>& rectangle)
		: Values(rectangle)
	{
		Row = Values.size();
		Col = Values[0].size();
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int i = row1; i <= row2; ++i)
		{
			for (int j = col1; j <= col2; ++j)
			{
				Values[i][j] = newValue;
			}
		}
	}

	int getValue(int row, int col) {
		return Values[row][col];
	}
};
