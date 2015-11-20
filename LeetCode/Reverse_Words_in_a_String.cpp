//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update(2015 - 02 - 12) :
//For C programmers : Try to solve it in - place in O(1) space.

#include <vector>
#include <string>
#include <sstream>

using namespace std;

void reverseWords(string &s)
{
	stringstream ss;
	string str;
	ss << s;
	vector<string> all_words;
	while (ss >> str)
		all_words.push_back(str);
	size_t sz = all_words.size();
	if (sz == 0)
	{
		s = "";
		return;
	}
	s = all_words[sz - 1];
	for (int i = sz - 2; i >= 0; --i)
	{
		s.append(" ");
		s.append(all_words[i]);
	}
}

void testReverseWords()
{
	//string str = "the sky is blue";
	string str = " ";
	reverseWords(str);
}