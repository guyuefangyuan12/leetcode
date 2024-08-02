#include<vector>
#include<functional>
using namespace std;

class Solution
{
public:
	int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime)
	{
		int n = values.size();
		vector<vector<int>> g(n, vector<int>(n, 0));
		vector<int> visit(n, 0);
		int ans = 0;
		visit[0] = 1;
		for (auto& i : edges)
		{
			g[i[0]][i[1]] = i[2];
			g[i[1]][i[0]] = i[2];
		}
		function<void(int, int, int)> DFS = [&](int i, int time, int value)
			{
				if (i == 0)
				{
					ans = max(ans, value);
				}
				for (int j = 0; j < n; j++)
				{
					if (g[i][j] != 0 && g[i][j] + time < maxTime)
					{
						if (visit[j]) 
						{
							DFS(j, time + g[i][j], value);
						}
						else 
						{
							visit[j] = 1;
							DFS(j, time + g[i][j], value + values[j]);
							visit[j] = 0;//»Ö¸´ÏÖ³¡
						}
					}
				}
			};
		DFS(0, 0, values[0]);
		return ans;
	}
};