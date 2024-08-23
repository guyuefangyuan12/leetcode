#include<vector>
using namespace std;

class Solution
{
public:
	bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color)
	{
		int r = rMove;
		int c = cMove + 1;
		bool flag = false;
		while (c < 8)
		{
			if (board[r][c] == '.')
			{
				break;
			}
			else
			{
				if (flag)
				{
					if (board[r][c] == color)
					{
						return  true;
					}
					else
					{
						c++;
					}
				}
				else
				{
					if (board[r][c] == color)
					{
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
		}

		flag = false;
		r = rMove;
		c = cMove - 1;
		while (c >= 0)
		{
			if (board[r][c] == '.')
			{
				break;
			}
			else
			{
				if (flag)
				{
					if (board[r][c] == color)
					{
						return  true;
					}
					else
					{
						c--;
					}
				}
				else
				{
					if (board[r][c] == color)
					{
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
		}

		flag = false;
		r = rMove + 1;
		c = cMove;
		while (r < 8)
		{
			if (board[r][c] == '.')
			{
				break;
			}
			else
			{
				if (flag)
				{
					if (board[r][c] == color)
					{
						return  true;
					}
					else
					{
						r++;
					}
				}
				else
				{
					if (board[r][c] == color)
					{
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
		}

		flag = false;
		r = rMove - 1;
		c = cMove;
		while (r >= 0)
		{
			if (board[r][c] == '.')
			{
				break;
			}
			else
			{
				if (flag)
				{
					if (board[r][c] == color)
					{
						return  true;
					}
					else
					{
						r--;
					}
				}
				else
				{
					if (board[r][c] == color)
					{
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
		}

		flag = false;
		r = rMove - 1;
		c = cMove - 1;
		while (r >= 0 && c >= 0)
		{
			if (board[r][c] == '.')
			{
				break;
			}
			else
			{
				if (flag)
				{
					if (board[r][c] == color)
					{
						return  true;
					}
					else
					{
						r--;
						c--;
					}
				}
				else
				{
					if (board[r][c] == color)
					{
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
		}

		flag = false;
		r = rMove - 1;
		c = cMove + 1;
		while (r >= 0 && c < 8)
		{
			if (board[r][c] == '.')
			{
				break;
			}
			else
			{
				if (flag)
				{
					if (board[r][c] == color)
					{
						return  true;
					}
					else
					{
						r--;
						c++;
					}
				}
				else
				{
					if (board[r][c] == color)
					{
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
		}

		flag = false;
		r = rMove + 1;
		c = cMove + 1;
		while (r < 8 && c < 8)
		{
			if (board[r][c] == '.')
			{
				break;
			}
			else
			{
				if (flag)
				{
					if (board[r][c] == color)
					{
						return  true;
					}
					else
					{
						r++;
						c++;
					}
				}
				else
				{
					if (board[r][c] == color)
					{
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
		}

		flag = false;
		r = rMove + 1;
		c = cMove - 1;
		while (r < 8 && c >= 0)
		{
			if (board[r][c] == '.')
			{
				break;
			}
			else
			{
				if (flag)
				{
					if (board[r][c] == color)
					{
						return  true;
					}
					else
					{
						r++;
						c--;
					}
				}
				else
				{
					if (board[r][c] == color)
					{
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
		}

		return false;
	}
};