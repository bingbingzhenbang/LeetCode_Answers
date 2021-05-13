#include <vector>

using namespace std;

int game(vector<int>& guess, vector<int>& answer) {
	int N = guess.size(), ret = 0;
	for (auto i = 0; i < N; ++i)
	{
		if (guess[i] == answer[i])
			++ret;
	}
	return ret;
}