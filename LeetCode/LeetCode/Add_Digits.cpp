//Given a non-negative integer num, repeatedly add all its digits until the result has only one digit. 
//
//	For example: 
//
//Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it. 
//
//	Follow up:
//Could you do it without any loop/recursion in O(1) runtime? 

#include <iostream>

using namespace std;

int addDigits(int num) 
{
	int r = num % 9;
	return (r == 0 && num > 0) ? 9 : r;
}

void testAddDigits()
{
	int n;
	cin>>n;
	int rt = addDigits(n);
	cout<<rt<<endl;
}