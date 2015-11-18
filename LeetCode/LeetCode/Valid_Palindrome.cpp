//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases. 
//
//	For example,
//	"A man, a plan, a canal: Panama" is a palindrome.
//	"race a car" is not a palindrome. 
//
//Note:
//Have you consider that the string might be empty? This is a good question to ask during an interview.
//
//	For the purpose of this problem, we define empty string as valid palindrome. 

#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
	if (s.empty())
		return true;
	string str;
	for (string::iterator itr = s.begin(); itr != s.end(); ++itr)
	{
		if (isalpha(*itr) || isdigit(*itr))
			str.push_back(tolower(*itr));
	}	
	for (int i = 0, j = str.size() - 1; i <= j; ++i, --j)
	{
		if (str[i] != str[j])
			return false;
	}
	return true;
}