//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non - negative integers, +, -, *, / operators and empty spaces.The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples :
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
//Note : Do not use the eval built - in library function.

#include <string>
#include <stack>
#include <cctype>

using namespace std;

int calculate2(string s)
{
	int size = s.size();
	if (size == 0)
		return 0;
	stack<int> nums;
	int lastnum = 0;
	char lastop = '+';
	for (int i = 0; i < size; ++i)
	{
		char ch = s[i];
		if (isdigit(ch))
		{
			if (lastnum == 0)
				lastnum = ch - '0';
			else
			{
				lastnum *= 10;
				lastnum += ch - '0';
			}
		}
		if (!isspace(ch) && !isdigit(ch) || i == size - 1)
		{
			switch (lastop)
			{
			case '+':
				nums.push(lastnum);
				break;
			case '-':
				nums.push(-lastnum);
				break;
			case '*':
			   {
						int left = nums.top();
						nums.pop();
						nums.push(left * lastnum);
			   }
			   break;
			case '/':
			   {
						int left = nums.top();
						nums.pop();
						nums.push(left / lastnum);
			    }
				break;
			}
			lastnum = 0;
			lastop = ch;
		}
	}
	int ret = 0;
	while (!nums.empty())
	{
		ret += nums.top();
		nums.pop();
	}
	return ret;
}

void testCalculate2()
{
	string s = " 1+2+6/5*7-2 ";
	int rt = calculate2(s);
}