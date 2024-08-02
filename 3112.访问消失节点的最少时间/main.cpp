#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;

struct pair_hash {
	template<class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2>& p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
};

class Solution
{
public:
	vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
	{
		vector<vector<pair<int, int>>> g(n);
		vector<int> ans(n, INT16_MAX);
		vector<bool> visit(n, false);
		unordered_map<pair<int, int>, bool,pair_hash> canch;
		for (auto i : edges)
		{
			g[i[0]].push_back(make_pair(i[1], i[2]));
			g[i[1]].push_back(make_pair(i[0], i[2]));
		}
		function<void(int, int)> dfs = [&](int i, int time)
			{
				if (time < disappear[i] && !canch.count(make_pair(i, time)))
				{
					visit[i] = true;
					ans[i] = min(ans[i], time);
					for (auto& k : g[i])
					{
						if (!visit[k.first])
						{
							dfs(k.first, time + k.second);
						}
					}
					visit[i] = false;
					canch[make_pair(i, time)] = true;
				}
			};
		dfs(0, 0);
		for (auto& i : ans)
		{
			if (i == INT16_MAX)
			{
				i = -1;
			}
		}
		return ans;
	}
};

