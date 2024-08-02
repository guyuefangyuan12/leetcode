#include<vector>
#include<functional>
#include<queue>
using namespace std;

class Solution
{
public:
	vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
	{
		vector<vector<pair<int, int>>> g(n);
		vector<int> ans(n, -1);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		vector<bool> visit(n, false);
		for (auto i : edges)
		{
			g[i[0]].push_back(make_pair(i[1], i[2]));
			g[i[1]].push_back(make_pair(i[0], i[2]));
		}
		function<void(int, int)> dfs = [&](int i, int time)
			{
				for (auto k : g[i])
				{
					if (!visit[k.first] && disappear[k.first] > time + k.second)
					{
						q.push(make_pair(time + k.second, k.first));
					}
				}
			};
		q.push(make_pair(0, 0));
		while (!q.empty()) 
		{
			pair<int, int> p = q.top();
			q.pop();
			if (!visit[p.second]) 
			{
				visit[p.second] = true;
				dfs(p.second, p.first);
				ans[p.second]= p.first;
			}			
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> edges = { {0,1,1} };
	vector<int> disapper = { 1,1 };
	Solution s;
	s.minimumTime(2, edges, disapper);
}