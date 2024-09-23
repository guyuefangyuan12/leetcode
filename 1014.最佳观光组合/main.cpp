#include<vector>
using namespace std;

class Solution
{
public:
	int maxScoreSightseeingPair(vector<int>& values)
	{
		int n = values.size();
		int ans = 0;
		int mx = values[0];
		for (int i = 1; i < n; i++)
		{
			ans = max(ans, values[i] - i + mx);
			mx = max(mx, values[i] + i);
		}
		return ans;
	}
};