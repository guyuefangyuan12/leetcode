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
		vector<int> s;
		vector<int> d;
		for (int i = 0; i < n; i++)
		{
			if (cards[i] % 2)
			{
				s.push_back(cards[i]);
			}
			else
			{
				d.push_back(cards[i]);
			}
		}
		int s_pos = s.size() - 1;
		int d_pos = d.size() - 1;
		int ans = 0;
		while (cnt)
		{
			int s_max = 0;
			int d_max1 = 0;
			int d_max2 = 0;
			if (cnt == 1)
			{
				if (d_pos >= 0)
				{
					ans += d[d_pos];
				}
				else
				{
					ans = 0;
				}
				break;
			}
			if (s_pos > 0)
			{
				s_max = s[s_pos] + s[s_pos - 1];
			}
			if (d_pos > 1)
			{
				d_max1 = d[d_pos];
				d_max2 = d[d_pos] + d[d_pos - 1];
				if (d_max1 >= s_max)
				{
					ans += d_max1;
					d_pos--;
					cnt--;
				}
				else if (d_max2 > s_max)
				{
					ans += d_max2;
					d_pos -= 2;
					cnt -= 2;
				}
				else
				{
					ans += s_max;
					s_pos -= 2;
					cnt -= 2;
				}
			}
			else if (d_pos == 1)
			{
				d_max1 = d[d_pos];
				d_max2 = d[d_pos] + d[d_pos - 1];
				if (s_max > d_max2)
				{
					ans += s_max;
					s_pos -= 2;
					cnt -= 2;
				}
				else if (d_max1 >= s_max)
				{
					ans += d_max1;
					d_pos--;
					cnt--;
				}
				else
				{
					if ((cnt - 2) % 2)
					{
						ans += d_max1;
						d_pos--;
						cnt--;
					}
					else
					{
						if (cnt - 2 <= s_pos + 1)
						{
							for (int i = s_pos; i >= s_pos + 3 - cnt; i--)
							{
								ans += s[i];
							}
							ans += d_max2;
							break;
						}
						else
						{
							ans = 0;
							break;
						}
					}
				}
			}
			else if (d_pos == 0)
			{
				d_max1 = d[d_pos];
				if (s_max > d_max1)
				{
					ans += s_max;
					s_pos -= 2;
					cnt -= 2;
				}
				else
				{
					if ((cnt - 1) % 2)
					{
						if (cnt <= s_pos + 1)
						{
							for (int i = s_pos; i >= s_pos + 1 - cnt; i--)
							{
								ans += s[i];
							}
							break;
						}
						else
						{
							ans = 0;
							break;
						}
					}
					else
					{
						if (cnt - 1 <= s_pos + 1)
						{
							for (int i = s_pos; i >= s_pos + 2 - cnt; i--)
							{
								ans += s[i];
							}
							ans += d_max1;
							break;
						}
						else
						{
							ans = 0;
							break;
						}
					}
				}
			}
			else if (d_pos < 0)
			{
				if (cnt % 2)
				{
					ans = 0;
					break;
				}
				else
				{
					if (cnt <= s_pos + 1)
					{
						for (int i = s_pos; i >= s_pos + 1 - cnt; i--)
						{
							ans += s[i];
						}
						break;
					}
				}
			}
		}
		return ans;
	}
};

