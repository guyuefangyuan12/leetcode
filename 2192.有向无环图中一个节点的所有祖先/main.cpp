#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	void dfs(vector<vector<int>>& g, vector<int>& visit, int i)
	{
		visit[i] = 1;
		for (auto& y : g[i]) 
		{
			if (visit[y] == 0)
			{
				dfs(g, visit, y);
			}
		}
	}
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
	{
		vector<vector<int>>g(n);
		vector<vector<int>>ans(n);		
		for (int i = 0; i < edges.size(); i++)
		{
			g[edges[i][1]].push_back(edges[i][0]);
		}
		for (int i = 0; i < n; i++) 
		{
			vector<int> visit(n, 0);
			dfs(g, visit, i);
			visit[i] = 0;
			for (int j = 0; j < n; j++) 
			{
				if (visit[j]) 
				{
					ans[i].push_back(j);
				}
			}
		}
		return ans;
	}
};
int main() {
	vector<vector<int>> edges = { {0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6} };
	Solution s;
	s.getAncestors(8, edges);
}