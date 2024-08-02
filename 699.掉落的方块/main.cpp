#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	vector<int> fallingSquares(vector<vector<int>>& positions)
	{
		int n = positions.size();
		vector<int> ans(n, 0);
		vector<vector<int>> l(n, vector<int>(3));
		ans[0] = positions[0][1];
		l[0][0] = positions[0][0];
		l[0][1] = positions[0][0] + positions[0][1];
		l[0][2] = positions[0][1];
		for (int i = 1; i < n; i++)
		{
			int high = 0;
			for (int j = 0; j < i; j++)
			{
				if (!(positions[i][0] >= l[j][1] || positions[i][0] + positions[i][1] <= l[j][0]))
				{
					high = max(high, l[j][2]);
				}
			}
			l[i][0] = positions[i][0];
			l[i][1] = positions[i][0] + positions[i][1];
			l[i][2] = positions[i][1] + high;
			ans[i] = max(ans[i - 1], l[i][2]);
		}
		return ans;
	}
};