//A message containing letters from A - Z is being encoded to numbers using the following mapping :
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//
//
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.

#include <string>
#include <vector>

using namespace std;

int numDecodings(string s)
{
	int sz = s.size();
	if (sz == 0)
		return 0;
	else if (sz == 1)
		return s[0] != '0';
	else if (sz == 2)
		return (s[0] != '0' && s[1] != '0') + (s[0] != '0' && stoi(s) <= 26);
	vector<int> dp(sz, 0);
	string temp = s.substr(0, 2);
	dp[0] = (s[0] != '0');
	dp[1] = (s[0] != '0' && s[1] != '0') + (s[0] != '0' && stoi(temp) <= 26);
	for (int i = 2; i < sz; ++i)
	{
		string temp = s.substr(i - 1, 2);
		dp[i] = dp[i - 1] * (s[i] != '0') + dp[i - 2] * (s[i - 1] != '0' && stoi(temp) <= 26);
	}
	return dp[sz - 1];
}

void testNumDecodings()
{
	//int rt = numDecodings("101");
	int rt = numDecodings("6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155");
}