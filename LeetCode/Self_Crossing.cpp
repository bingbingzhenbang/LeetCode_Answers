//You are given an array x of n positive numbers.You start at point(0, 0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on.In other words, after each move your direction changes counter - clockwise.
//
//Write a one - pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.
//
//Example 1:
//Given x = [2, 1, 1, 2],
//©°©¤©¤©¤©´
//©¦   ©¦
//©¸©¤©¤©¤©à©¤©¤ >
//©¦
//
//Return true (self crossing)
//Example 2:
//Given x = [1, 2, 3, 4],
//©°©¤©¤©¤©¤©¤©¤©´
//©¦      ©¦
//©¦
//©¦
//©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤ >
//
//Return false (not self crossing)
//Example 3:
//Given x = [1, 1, 1, 1],
//©°©¤©¤©¤©´
//©¦   ©¦
//©¸©¤©¤©¤©à >
//
//Return true (self crossing)

#include <vector>
#include <algorithm>

using namespace std;

bool isSelfCrossing(vector<int>& x)
{
	x.insert(x.begin(), 4, 0);
	int size = x.size(), i = 4;
	for (; i < size && x[i] > x[i - 2]; ++i)
		;
	if (i == size)
		return false;
	if (x[i] >= x[i - 2] - x[i - 4])
		x[i - 1] -= x[i - 3];
	++i;
	for (; i < size && x[i] < x[i - 2]; ++i)
		;
	return i != size;
}

bool isSelfCrossing2(vector<int>& x)
{
	int size = x.size(), i = 2;
	if (size < 4)
		return false;
	for (; i < size && x[i] > x[i - 2]; ++i)
		;
	if (i == size)
		return false;
	if (i >= 4 && x[i] >= x[i - 2] - x[i - 4] || (i == 3 && x[i] == x[i - 2]))
		x[i - 1] -= x[i - 3];
	++i;
	for (; i < size && x[i] < x[i - 2]; ++i)
		;
	return i != size;
}