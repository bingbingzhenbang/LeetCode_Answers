#include <vector>

using namespace std;

void addCombination(vector<vector<int>> &result, vector<int>& currentResult, int currentIndex, vector<int> &candidates, int target)
{
	if (target == 0)
	{
		result.push_back(currentResult);
		return;
	}
	if (currentIndex == candidates.size())
		return;
	addCombination(result, currentResult, currentIndex + 1, candidates, target);
	if (target >= candidates[currentIndex])
	{
		currentResult.push_back(candidates[currentIndex]);
		addCombination(result, currentResult, currentIndex, candidates, target - candidates[currentIndex]);
		currentResult.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	vector<int> currentResult;
	addCombination(ret, currentResult, 0, candidates, target);
	return ret;
}