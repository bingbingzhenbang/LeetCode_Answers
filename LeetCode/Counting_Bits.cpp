//Given a non negative integer number num.For every numbers i in the range 0 ¡Ü i ¡Ü num calculate the number of 1's in their binary representation and return them as an array. 
//
//Example:
//For num = 5 you should return[0, 1, 1, 2, 1, 2].
//
//Follow up :
//It is very easy to come up with a solution with run time O(n*sizeof(integer)).But can you do it in linear time O(n) / possibly in a single pass ?
//Space complexity should be O(n).
//Can you do it like a boss ? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
//
//
//Hint :
//	 1.You should make use of what you have produced already.
//	 2.Divide the numbers in ranges like[2 - 3], [4 - 7], [8 - 15] and so on.And try to generate new range from previous.

#include <vector>

using namespace std;

vector<int> countBits(int num)
{
	if (num < 0)
		return vector<int>();
	vector<int> result(num + 1, 0);
	if (num == 0)
		return result;
	else if (num >= 1)
	{
		result[1] = 1;
		int index = 2, begin = 2, end = 4;
		while (begin <= num)
		{
			for (index = begin; index <= num && index < end; ++index)
			{
				result[index] = result[index - begin] + 1;
			}
			begin = end;
			end *= 2;
		}
	}
	return result;
}

void testCountBits()
{
	int num = 2;
	vector<int> rt = countBits(num);
}