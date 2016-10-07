//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//For example,
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be :
//
//X X X X
//X X X X
//X X X X
//X O X X

#include <vector>

using namespace std;

void turnoto1(vector<vector<char>>& board, int i, int j, int m, int n)
{
	if (board[i][j] != 'O')
		return;
	board[i][j] = '1';
	if (i > 1)
		turnoto1(board, i - 1, j, m, n);
	if (i < m - 1)
		turnoto1(board, i + 1, j, m, n);
	if (j > 1)
		turnoto1(board, i, j - 1, m, n);
	if (j < n - 1)
		turnoto1(board, i, j + 1, m, n);
}

void solve(vector<vector<char>>& board)
{
	int m = board.size();
	if (m == 0)
		return;
	int n = board[0].size();
	if (n == 0)
		return;
	for (int i = 0; i < m; ++i)
		turnoto1(board, i, 0, m, n);
	if (n > 1)
	{
		for (int i = 0; i < m; ++i)
			turnoto1(board, i, n - 1, m, n);
	}
	for (int j = 0; j < n; ++j)
		turnoto1(board, 0, j, m, n);
	if (m > 1)
	{
		for (int j = 0; j < n; ++j)
			turnoto1(board, m - 1, j, m, n);
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == 'O')
				board[i][j] = 'X';
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == '1')
				board[i][j] = 'O';
		}
	}
}