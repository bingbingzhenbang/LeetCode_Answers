//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//	The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <string>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s)
{
	map<char, char> compareChars;
	compareChars['('] = ')';
	compareChars['['] = ']';
	compareChars['{'] = '}';
	stack<char> char_stack;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			char_stack.push(s[i]);
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (!char_stack.empty() && compareChars[char_stack.top()] == s[i])
			{
				char_stack.pop();
			}
			else
				return false;
		}
	}
	return char_stack.empty();
}

void testIsValid()
{
	//string str = "{[([{}])]}";
	string str = "()";
	bool rt = isValid(str);
}