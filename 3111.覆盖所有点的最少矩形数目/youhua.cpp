#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int minRectanglesToCoverPoints(vector<vector<int>>& points, int w)
	{
		int n = points.size();
		vector<int> x;
		for (int i = 0; i < n; i++)
		{
			x.push_back(points[i][0]);
		}
		sort(x.begin(), x.end());
		int ans = 0;
		int cnt = -1;
		for (int pos : x)
		{
			if (cnt < pos)
			{
				cnt = pos + w;
				ans++;
			}
		}
		return ans;
	}
};