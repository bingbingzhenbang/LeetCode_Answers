//A binary watch has 4 LEDs on the top which represent the hours(0 - 11), and the 6 LEDs on the bottom represent the minutes(0 - 59).
//
//Each LED represents a zero or one, with the least significant bit on the right.
//For example, the above binary watch reads "3:25".
//
//Given a non - negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
//Example:
//
//Input : n = 1
//Return : ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//	 Note :
//		  The order of output does not matter.
//		  The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
//		  The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

#include <vector>
#include <string>
#include <bitset>

using namespace std;

vector<string> readBinaryWatch(int num)
{
	vector<string> result;
	for (int h = 0; h < 12; ++h)
	{
		for (int m = 0; m < 60; ++m)
		{
			bitset<4> bh(h);
			bitset<6> bm(m);
			if (bh.count() + bm.count() == num)
			{
				string temp;
				if (m < 10)
					temp = to_string(h) + ":0" + to_string(m);
				else
					temp = to_string(h) + ":" + to_string(m);
				result.push_back(temp);
			}
		}
	}
	return result;
}

void getBinaryWatch(vector<string> &result, vector<int> &bits, int num, int currentLed, int bitsindex, int hour, int min)
{
	if (hour > 11 || min > 59)
		return;
	if (num == currentLed)
	{
		string temp;
		if (min < 10)
			temp = to_string(hour) + ":0" + to_string(min);
		else
			temp = to_string(hour) + ":" + to_string(min);
		result.push_back(temp);
		return;
	}
	for (int index = bitsindex; index < bits.size(); ++index)
	{
		if (index < 4)
			getBinaryWatch(result, bits, num, currentLed + 1, index + 1, hour + bits[index], min);
		else
			getBinaryWatch(result, bits, num, currentLed + 1, index + 1, hour, min + bits[index]);
	}
}

vector<string> readBinaryWatch2(int num)
{
	vector<string> result;
	vector<int> bits = { 1, 2, 4, 8, 1, 2, 4, 8, 16, 32 };
	getBinaryWatch(result, bits, num, 0, 0, 0, 0);
	return result;
}