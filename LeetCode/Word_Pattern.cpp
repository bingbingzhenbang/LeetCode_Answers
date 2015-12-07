//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.
//
//Examples:
//
//1.pattern = "abba", str = "dog cat cat dog" should return true.
//2.pattern = "abba", str = "dog cat cat fish" should return false.
//3.pattern = "aaaa", str = "dog cat cat dog" should return false.
//4.pattern = "abba", str = "dog dog dog dog" should return false.
//
//
//Notes :
//	  You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

bool wordPattern(string pattern, string str)
{
	int sz = pattern.size(), i = 0;
	unordered_map<char, string> ch2str;
	unordered_map<string, char> str2ch;
	stringstream ss;
	string temp;
	ss << str;
	while (ss >> temp)
	{
		if (i >= sz)
			return false;
		char ch = pattern[i];
		auto itr1 = ch2str.find(ch);
		auto itr2 = str2ch.find(temp);
		if (itr1 != ch2str.end() && itr2 != str2ch.end())
		{
			if (itr1->second != temp || itr2->second != ch)
				return false;
			else
				++i;
		}
		else if (itr1 == ch2str.end() && itr2 == str2ch.end())
		{
			ch2str[ch] = temp;
			str2ch[temp] = ch;
			++i;
		}
		else
			return false;
	}
	return i == sz;
}

void testWordPattern()
{
	bool rt = wordPattern("jquery", "jquery");
}