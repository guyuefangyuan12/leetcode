#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
	int maximumDetonation(vector<vector<int>>& bombs)
	{
		int n = bombs.size();
		vector<bool> vis(n, false);//炸弹是否被引爆的列表
		vector<vector<int>> d(n);//当前炸弹被引爆时能够引爆的炸弹列表
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j != i && (pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2))<= pow(bombs[i][2], 2))
				{
					d[i].push_back(j);
				}
			}
		}
		function<int(int)> dfs = [&](int i)->int
			{
				int cnt = 0;
				vis[i] = true;
				for (int& b : d[i]) 
				{
					if (!vis[b]) 
					{
						cnt=dfs(b)+1+cnt;
					}
				}
				return cnt;
			};
		int ans = 0;
		for (int i = 0; i < n; i++) 
		{
			vis[i] = true;
			ans=max(dfs(i)+1,ans);
			fill(vis.begin(), vis.end(), false);
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> bombs = { {2,1,3},{6,1,4} };
	Solution s;
	s.maximumDetonation(bombs);
}