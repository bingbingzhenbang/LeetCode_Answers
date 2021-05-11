#include <string>

using namespace std;

string reverseLeftWords(string s, int n) {
	int sz = s.size();
	int first = n % sz;
	int remain = sz - first;
	string ret(s);
	string temp(s.begin(), s.begin() + first);
	for (auto i = 0; i < remain; ++i)
		ret[i] = s[i + first];
	for (auto i = remain; i < sz; ++i)
		ret[i] = temp[i - remain];
	return ret;
}