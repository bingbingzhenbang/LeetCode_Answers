//Given an absolute path for a file(Unix - style), simplify it.
//
//For example,
//path = "/home/", = > "/home"
//path = "/a/./b/../../c/", = > "/c"
//
//
//click to show corner cases.
//
//Corner Cases :
//
//Did you consider the case where path = "/../" ?
//In this case, you should return "/".
//Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo".

#include <string>
#include <stack>
#include <sstream>

using namespace std;

string simplifyPath(string path)
{
	stack<string> s;
	string str;
	for (int i = 0; i < path.length(); ++i)
	{
		if (path[i] == '/')
			path[i] = ' ';
	}
	istringstream ss(path);
	while (ss >> str)
	{
		if (str == ".." && !s.empty())
			s.pop();
		else if (str == "." || str == ".." && s.empty()) 
		{
		}
		else
			s.push(str);
	}
	string res = "";
	if (s.empty()) {
		return "/";
	}
	while (!s.empty())
	{
		res = "/" + s.top() + res;
		s.pop();
	}
	return res;
}

void testSimplifyPath()
{
	//string rt = simplifyPath("/a/./b/../../c/");
	//string rt = simplifyPath("/a//b//c/");
	string rt = simplifyPath("/a/b/d/../../c/");
}