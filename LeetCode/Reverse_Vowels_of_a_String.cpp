//Write a function that takes a string as input and reverse only the vowels of a string.
//
//Example 1:
//Given s = "hello", return "holle".
//
//Example 2 :
//Given s = "leetcode", return "leotcede".

#include <string>

using namespace std;

bool isVowel(char input_ch)
{
	char ch = tolower(input_ch);
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string s)
{
	string vowels;
	for (auto itr = s.begin(); itr != s.end(); ++itr)
	{
		if (isVowel(*itr))
			vowels.push_back(*itr);
	}
	string::iterator itr1 = s.begin();
	string::reverse_iterator itr2 = vowels.rbegin();
	for (; itr1 != s.end(); ++itr1)
	{
		if (isVowel(*itr1))
		{
			*itr1 = *itr2;
			++itr2;
		}
	}
	return s;
}