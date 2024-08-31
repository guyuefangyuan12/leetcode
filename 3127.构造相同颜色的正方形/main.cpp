#include<vector>
using namespace std;

class Solution
{
public:
	bool canMakeSquare(vector<vector<char>>& grid)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int flag = 0;
				if (grid[i + 1][j] == grid[i][j])
				{
					flag++;
				}
				if (grid[i][j + 1] == grid[i][j])
				{
					flag++;
				}
				if (grid[i + 1][j + 1] == grid[i][j])
				{
					flag++;
				}
				if (flag != 1) 
				{
					return true;
				}
			}
		}
		return false;
	}
};