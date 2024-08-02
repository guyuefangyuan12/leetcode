#include<vector>
#include<set>
using namespace std;

class Solution
{
public:
	int minRectanglesToCoverPoints(vector<vector<int>>& points, int w)
	{
		int n = points.size();
		set<int> x;
		for (int i = 0; i < n; i++)
		{
			x.insert(points[i][0]);
		}
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