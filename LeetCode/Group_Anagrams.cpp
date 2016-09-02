//Given an array of strings, group anagrams together.
//
//For example, given:["eat", "tea", "tan", "ate", "nat", "bat"],
//Return :
//
//	   [
//		   ["ate", "eat", "tea"],
//		   ["nat", "tan"],
//		   ["bat"]
//	   ]
//Note: All inputs will be in lower - case.

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	map< multiset<char>, vector<string> > letters2str;
	for (auto sitr = strs.begin(); sitr != strs.end(); ++sitr)
		letters2str[multiset<char>(sitr->begin(), sitr->end())].push_back(*sitr);
	vector< vector<string> > result;
	for (auto itr = letters2str.begin(); itr != letters2str.end(); ++itr)
		result.push_back(itr->second);
	return result;
}

vector< vector<string> > groupAnagrams2(vector<string>& strs)
{
	vector< vector<string> > result;
	if (strs.empty()) 
		return result;
	unordered_map< string, vector<string> > h;
	for (int i = 0; i < strs.size(); ++i)
	{
		string s = strs[i];
		sort(s.begin(), s.end());
		h[s].push_back(strs[i]);
	}
	for (auto itr = h.begin(); itr != h.end(); ++itr)
		result.push_back(itr->second);
	return result;
}

void testGroupAnagrams()
{
	vector<string> strs = { "hos", "boo", "nay", "deb", "wow", "bop", "bob", "brr", "hey", "rye", "eve", "elf", "pup", "bum", "iva", "lyx", "yap", "ugh", "hem", "rod", "aha", "nam", "gap", "yea", "doc", "pen", "job", "dis", "max", "oho", "jed", "lye", "ram", "pup", "qua", "ugh", "mir", "nap", "deb", "hog", "let", "gym", "bye", "lon", "aft", "eel", "sol", "jab" };
	vector< vector<string> > rt = groupAnagrams(strs);
}