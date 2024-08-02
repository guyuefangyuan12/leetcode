#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
	int maxmiumScore(vector<int>& cards, int cnt)
	{
		int n = cards.size();
		sort(cards.begin(), cards.end());
		int ans = 0;
		int pos1 = n;
		int pos2 = n;
		int pos3 = n;
		int pos4 = n;
		for (int i = n - 1; i >= n  - cnt; i--)
		{
			if (cards[i] % 2)
			{
				pos1 = i;
			}
			else
			{
				pos2 = i;
			}
			ans += cards[i];
		}
		for (int i = n - 1 - cnt; i >= 0; i--)
		{
			if ((cards[i] % 2) && pos3 == n)
			{
				pos3 = i;
			}
			if (!(cards[i] % 2) && pos4 == n)
			{
				pos4 = i;
			}
		}
		if (ans % 2)
		{
			if (pos3 == n)
			{
				if (pos4 == n)
				{
					return 0;
				}
				else
				{
					ans = ans - cards[pos1] + cards[pos4];
				}
			}
			else
			{
				if (pos4 == n)
				{
					if (pos2 != n)
					{
						ans = ans - cards[pos2] + cards[pos3];
					}
					else
					{
						return 0;
					}
				}
				else
				{
					if (pos2 != n)
					{
						ans = max(ans - cards[pos2] + cards[pos3], ans - cards[pos1] + cards[pos4]);
					}
					else
					{
						ans = ans - cards[pos1] + cards[pos4];
					}
				}
			}
		}
		else
		{
			return ans;
		}
		return ans;
	}
};

