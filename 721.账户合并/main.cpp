#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
	{
		int n = accounts.size();
		vector<vector<string>>ans;
		unordered_map<string, vector<int>>map;
		unordered_set<string> s;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < accounts[i].size(); j++)
			{
				map[accounts[i][j]].push_back(i);
			}
		}
		vector<bool> vis(n, false);
		function<void(int, vector<string>&)> dfs = [&](int i, vector<string>& str)
			{
				vis[i] = true;
				for (int k = 1; k < accounts[i].size(); k++)
				{
					if (!s.count(accounts[i][k]))
					{
						str.push_back(accounts[i][k]);
						s.insert(accounts[i][k]);
						for (auto& j : map[accounts[i][k]])
						{
							if (!vis[j])
							{
								dfs(j, str);
							}
						}
					}
				}
			};
		for (int i = 0; i < n; i++)
		{
			vector<string> temp;
			dfs(i, temp);
			if (temp.size())
			{
				sort(temp.begin(), temp.end());
				temp.insert(temp.begin(), accounts[i][0]);
				ans.push_back(temp);
			}
		}
		return ans;
	}
};
/*
int main()
{
	vector<vector<string>> acc = {
		{"John", "johnsmith@mail.com", "john00@mail.com"},
		{"John", "johnnybravo@mail.com"},
		{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
		{"Mary", "mary@mail.com"}
	};
	Solution s;
	s.accountsMerge(acc);
}
*/
