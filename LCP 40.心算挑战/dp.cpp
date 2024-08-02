#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;

class Solution
{
public:
	int maxmiumScore(vector<int>& cards, int cnt)
	{
		int n = cards.size();
		sort(cards.begin(), cards.end());
		unordered_map<long long, int> dp;
		for (int i = 0; i < n; i++)
		{
			dp[(cards[i] % 2) | i << 1 | 1 << 20] = max(cards[i], dp[(cards[i] % 2) | (i - 1) << 1 | 1 << 20]);
			dp[((cards[i] + 1) % 2) | i << 1 | 1 << 20] = dp[((cards[i] + 1) % 2) | (i - 1) << 1 | 1 << 20];
			for (int j = 2; j <= i + 1 && j <= cnt; j++)
			{
				dp[0 | i << 1 | j << 20] = max(dp[0 | (i - 1) << 1 | j << 20], dp[cards[i] % 2 | (i - 1) << 1 | (j - 1) << 20] ? dp[cards[i] % 2 | (i - 1) << 1 | (j - 1) << 20] + cards[i] : 0);
				dp[1 | i << 1 | j << 20] = max(dp[1 | (i - 1) << 1 | j << 20], dp[(cards[i] + 1) % 2 | (i - 1) << 1 | (j - 1) << 20] ? dp[(cards[i] + 1) % 2 | (i - 1) << 1 | (j - 1) << 20] + cards[i] : 0);
			}
		}
		return dp[0 | (n - 1) << 1 | cnt << 20];
	}
};

int main()
{
	vector<int>c = { 6,6,4,10,1,5,5,9,8,5 };
	Solution s;
	s.maxmiumScore(c, 7);
}