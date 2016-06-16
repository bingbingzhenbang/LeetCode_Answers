//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open(and closing parentheses), the plus + or minus sign - , non - negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples :
//
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
//
//
//
//Note : Do not use the eval built - in library function.

#include <string>
#include <cctype>
#include <stack>

using namespace std;

void calStack(stack<int> &numbers, stack<char> &ops)
{
	int left = numbers.top();
	numbers.pop();
	int right = numbers.top();
	numbers.pop();
	if (ops.top() == '+')
		numbers.push(left + right);
	if (ops.top() == '-')
		numbers.push(left - right);
	ops.pop();
}

int calculate(string s)
{
	int size = s.size();
	if (size == 0)
		return 0;
	int currentNum = 0;
	string currentNumStr;
	currentNumStr.reserve(100);
	stack<int> numbers;
	stack<char> ops;
	for (int i = size - 1; i >= 0; --i)
	{
		char ch = s[i];
		if (isspace(ch))
			continue;
		if (ch == ')' || ch == '+' || ch == '-')
		{
			ops.push(ch);
			continue;
		}
		if (isdigit(ch))
		{
			currentNumStr = ch + currentNumStr;
			if (i == 0 || i > 0 && !isdigit(s[i - 1]))
			{
				currentNum = stoi(currentNumStr);
				numbers.push(currentNum);
				currentNumStr.clear();
			}
		}
		else if (ch == '(')
		{
			while (ops.top() != ')')
				calStack(numbers, ops);
			ops.pop();
		}
	}
	while (!ops.empty())
		calStack(numbers, ops);
	return numbers.top();
}