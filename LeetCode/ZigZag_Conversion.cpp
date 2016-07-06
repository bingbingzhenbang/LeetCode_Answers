//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//And then read line by line : "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows :
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows)
{
	if (numRows == 1)
		return s;
	int size = s.size();
	int step = 2 * numRows - 2;
	vector<string> allRows(numRows);
	for (int i = 0; i < size; ++i)
	{
		char ch = s[i];
		int remain = i % step;
		if (remain < numRows)
			allRows[remain].push_back(ch);
		else
			allRows[step - remain].push_back(ch);
	}
	string result;
	for (int i = 0; i < numRows; ++i)
		result += allRows[i];
	return result;
}