#include<vector>
using namespace std;

class dijkstra
{
public:
	int dij(vector<vector<int>> edges, int n, int start, int end)
	{
		vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));//�����ڽӾ���
		for (auto& p : edges)
		{
			g[p[0]][p[1]] = p[2];
			g[p[1]][p[0]] = p[2];
		}
		vector<int> dis(n, INT_MAX / 2);//ÿ���������ʼ�����̾���
		vector<int> visit(n, false);//�Ƿ������
		dis[start] = 0;
		while (true)
		{
			int x = -1;//�ҵ���δ�������ĵ�ǰ������ʼ������ĵ�
			for (int i = 0; i < n; i++)
			{
				if (!visit[i] && (x == -1 || dis[i] < dis[x]))
				{
					x = i;
				}
			}
			if (x == -1 || dis[x] == INT_MAX / 2)//�Ѿ�û�ÿ��Ա����ĵ���
			{
				return -1;
			}
			if (x == end) //�ҵ����յ�
			{
				return dis[x];
			}
			for (int i = 0; i < n; i++)
			{
				dis[i] = min(dis[x] + g[x][i], dis[i]);
			}
		}
	}
};