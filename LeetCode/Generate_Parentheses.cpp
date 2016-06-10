//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//[
//	"((()))",
//	"(()())",
//	"(())()",
//	"()(())",
//	"()()()"
//]

#include <vector>
#include <string>

using namespace std;

// related to Catalan number 

void appendParenthesis(vector<string> &result, int left_remains, int right_remains, string str)
{
	if (left_remains == 0 && right_remains == 0)
	{
		result.push_back(str);
		return;
	}
	if (left_remains > 0)
		appendParenthesis(result, left_remains - 1, right_remains, str + "(");
	if (left_remains < right_remains)
		appendParenthesis(result, left_remains, right_remains - 1, str + ")");
}

vector<string> generateParenthesis(int n)
{
	if (n <= 0)
		return vector<string>();
	else
	{
		vector<string> result;
		appendParenthesis(result, n, n, "");
		return result;
	}
}

void testGenerateParenthesis()
{
	vector<string> rt = generateParenthesis(4);
}