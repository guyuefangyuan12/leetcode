#include<vector>
using namespace std;
//与官方思路一致，但求解过程还能优化
//1.DFS可以直接求解子树满足条件的节点个数，在主循环中判断子树的个数；
class Solution
{
public:
	void DFS(vector<vector<int>>& graph, vector<int>& visit, vector<int>& temp,vector<int>& length, vector<int>& flag, int v, int root, int signalSpeed)
	{
		visit[v] = 1;
		int cnt = 0;
		for (int i = 0; i < flag.size(); i++)
		{
			if (graph[v][i] && !visit[i])
			{
				if (v == root)
				{
					flag[i] = cnt;
					cnt++;
				}
				else
				{
					flag[i] = flag[v];
				}
				length[i] = length[v] + graph[v][i];
				if (length[i] % signalSpeed == 0) 
				{
					temp[flag[i]]++;
				}
				DFS(graph, visit,temp, length, flag, i, root,signalSpeed);
			}
		}
	}
	vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed)
	{
		int m = edges.size();
		int n = m + 1;
		vector<int> count(n);
		vector<vector<int>> graph(n, vector<int>(n, 0));
		for (auto i : edges)
		{
			graph[i[0]][i[1]] = i[2];
			graph[i[1]][i[0]] = i[2];
		}
		for (int i = 0; i < n; i++)
		{
			vector<int> length(n);
			vector<int> flag(n);
			vector<int> visit(n);
			vector<int> temp(n);
			DFS(graph, visit,temp,length, flag, i, i,signalSpeed);
			int sum = 0;
			int S = 0;
			for (int j = 0; j < temp.size(); j++)
			{
				S += temp[j];
			}
			for (int j = 0; j <temp.size(); j++)
			{
				sum += (S-temp[j])*temp[j];
			}
			count[i] = sum/2;
		}
		return count;
	}
};

int main()
{
	vector<vector<int>> edges = { {0,1,1},{1,2,5},{2,3,13},{3,4,9},{4,5,2} };
	Solution s;
	s.countPairsOfConnectableServers(edges, 1);
}