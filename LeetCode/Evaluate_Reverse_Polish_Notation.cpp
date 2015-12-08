//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//
//Some examples :
//
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <vector>
#include <string>
#include <stack>

using namespace std;

int calculateToken(int num1, int num2, const string &op)
{
	switch (op[0])
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	}
	return 0;
}

int evalRPN(vector<string>& tokens)
{
	stack<int> nums;
	int sz = tokens.size();
	for (int i = 0; i < sz; ++i)
	{
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			int num2 = nums.top();
			nums.pop();
			int num1 = nums.top();
			nums.pop();
			nums.push(calculateToken(num1, num2, tokens[i]));
		}
		else
			nums.push(stoi(tokens[i]));
	}
	return nums.top();
}

void testEvalRPN()
{

}