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
		unordered_map<long long, int> cache;
		function<int(int, int, int)> dfs = [&](int i, int j, int k)->int
			{
				if (i < 0)
				{
					return 0;
				}
				else
				{
					long long flag = k | i << 1 | j << 20;
					if (!cache.count(flag))
					{
						if (j == 1)
						{
							cache[flag] = (cards[i] % 2 == k ? cards[i] : dfs(i - 1, j, k));
							return cache[flag];
						}
						else
						{
							cache[flag] = max(dfs(i - 1, j, k), dfs(i - 1, j - 1, (k + cards[i]) % 2) ? dfs(i - 1, j - 1, (k + cards[i]) % 2) + cards[i] : 0);
							return cache[flag];
						}
					}
					else
					{
						return cache[flag];
					}
				}
			};
		int temp = dfs(n - 1, cnt, 0);
		return temp;
	}
};