#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int maximizeWin(vector<int>& prizePositions, int k)
	{
		int n = prizePositions.size();
		unordered_map<int, int> sum;
		vector<int> p;
		sum[prizePositions[0]] = 1;
		p.push_back(prizePositions[0]);
		for (int i = 1; i < n; i++)
		{
			if (prizePositions[i] != prizePositions[i - 1])
			{
				p.push_back(prizePositions[i]);
				sum[prizePositions[i]] = sum[prizePositions[i - 1]] + 1;
			}
			else
			{
				sum[prizePositions[i]]++;
			}
		}
		unordered_map<int, int>map;
		int temp = 0;
		int m = p.size();
		int pos = 0;
		for (int i = 0; i < m; i++)
		{
			while (pos != m && p[i] + k >= p[pos])
			{
				pos++;
			}
			map[p[i]] = sum[p[pos - 1]] - (i == 0 ? 0 : sum[p[i - 1]]);
		}
		unordered_map<int, int> m1;
		for (int i = m - 1; i >= 0; i--)
		{
			m1[p[i]] = max(temp, map[p[i]]);
			temp = m1[p[i]];
		}
		int ans = 0;
		pos = 0;
		for (int i = 0; i < m; i++)
		{
			while (pos != m && p[i] + k >= p[pos])
			{
				pos++;
			}
			ans = max(ans, map[p[i]] + (pos == m ? 0 : m1[p[pos]]));
		}
		return ans;
	}
};

int main() {
	vector<int> pri =
	{ 1,1,2,2,3,3,5
	};
	Solution s;
	s.maximizeWin(pri,2);
}