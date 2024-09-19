#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
	{
		if (source == target) {
			return 0;
		}
		int n = routes.size();
		vector<bool> r(n, false);
		unordered_map<int, vector<int>>map;
		unordered_map<int, int>m;
		for (int i = 0; i < n; i++)
		{
			for (int j : routes[i])
			{
				map[j].push_back(i);
			}
		}
		vector<int> temp1 = { target };
		vector<int> temp2;
		int cnt = 1;
		while (1)
		{
			bool flag = false;
			for (int k : temp1)
			{
				for (int i : map[k])
				{
					if (!r[i])
					{
						r[i] = true;
						flag = true;
						for (int j : routes[i])
						{
							if (!m.count(j))
							{
								m[j] = cnt;
								temp2.push_back(j);
							}
						}
					}
				}
			}
			temp1 = temp2;
			cnt++;
			if (!flag)
			{
				break;
			}
		}
		if (m.count(source))
		{
			return m[source];
		}
		return -1;
	}
};