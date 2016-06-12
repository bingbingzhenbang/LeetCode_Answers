//Given two words(beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that: 
//1.Only one letter can be changed at a time
//2.Each intermediate word must exist in the word list
//
//For example,
//
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot", "dot", "dog", "lot", "log"]
//
//
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//
//Note:
//
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.

#include <string>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
	queue< pair<int, string> > level_word;
	level_word.push(pair<int, string>(1, beginWord));
	wordList.erase(beginWord);
	while (!level_word.empty())
	{
		int level = level_word.front().first;
		string currentWord = level_word.front().second;
		level_word.pop();
		if (currentWord == endWord)
			return level;
		int size = currentWord.size();
		for (int i = 0; i < size; ++i)
		{
			for (char ch = 'a'; ch <= 'z'; ++ch)
			{
				string tempString = currentWord;
				tempString[i] = ch;
				if (wordList.find(tempString) != wordList.end())
				{
					level_word.push(pair<int, string>(level + 1, tempString));
					wordList.erase(tempString);
				}
			}
		}
	}
	return 0;
}