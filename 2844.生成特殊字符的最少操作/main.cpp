#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
	int minimumOperations(string num)
	{
		int n = num.size();
		vector<vector<int>> end(4);
		for (int i = 0; i < n; i++)
		{
			if (num[i] == '0')
			{
				end[0].push_back(i);
			}
			else if (num[i] == '5')
			{
				end[1].push_back(i);
			}
			else if (num[i] == '2')
			{
				end[2].push_back(i);
			}
			else if (num[i] == '7')
			{
				end[3].push_back(i);
			}
		}
		int ans = INT_MAX;
		for (int i = 0; i < 2; i++)
		{
			for (int j = end[i].size() - 1; j >= 0; j--)
			{
				int flag = 0;
				if (i == 0) 
				{
					for (int k = 0; k < 2; k++) 
					{
						for (int m = end[k].size() - 1; m >= 0; m--) 
						{
							if (end[i][j] > end[k][m]) 
							{
								ans = min(ans, n - 2 - end[k][m]);
								flag = 1;
								break;
							}
						}
					}
					ans = min(n - 1, ans);
					if (flag) 
					{
						break;
					}
				}
				else if (i == 1) 
				{
					for (int k = 2; k < 4; k++)
					{
						for (int m = end[k].size() - 1; m >= 0; m--)
						{
							if (end[i][j] > end[k][m])
							{
								ans = min(ans, n - 2 - end[k][m]);
								flag = 1;
								break;
							}
						}
					}
					if (flag) 
					{
						break;
					}
				}				
			}
		}
		ans = min(n, ans);
		return ans;
	}
};