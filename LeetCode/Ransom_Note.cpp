//Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom  note can be constructed from the magazines; otherwise, it will return false.
//
//Each letter in the magazine string can only be used once in your ransom note.
//
//Note:
//You may assume that both strings contain only lowercase letters.
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true

#include <string>
#include <set>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
	multiset<char> magletters(magazine.begin(), magazine.end());
	for (auto ritr = ransomNote.begin(); ritr != ransomNote.end(); ++ritr)
	{
		auto mitr = magletters.find(*ritr);
		if (mitr == magletters.end())
			return false;
		else
			magletters.erase(mitr);
	}
	return true;
}