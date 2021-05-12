#include <string>
#include <map>

using namespace std;

int numJewelsInStones(string jewels, string stones) {
	int N = jewels.size(), M = stones.size();
	map<char, int> count;
	for (int i = 0; i < N; ++i)
		count[jewels[i]] = 0;
	for (int i = 0; i < M; ++i)
		++count[stones[i]];
	int ret = 0;
	for (int i = 0; i < N; ++i)
		ret += count[jewels[i]];
	return ret;
}