#include<vector>
#include<string>
using namespace std;
//正难则反，与其维护两端，不如维护中间的子串。
class Solution
{
public:
	int takeCharacters(string s, int k)
	{
		int n = s.size();
		int l = -1;
		int r = n - 1;
		int ans = 0;
		vector<int> cnt(3, 0);
		if (k == 0)
		{
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			cnt[s[i] - 'a']++;
			if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k)
			{
				l = i - 1;
				cnt[s[i] - 'a']--;
				ans = i + 1;
				break;
			}
		}
		if (l == -1)
		{
			return -1;
		}
		while (l >= 0)
		{
			cnt[s[r] - 'a']++;
			r--;
			if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k)
			{
				while (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k)
				{
					cnt[s[l] - 'a']--;
					l--;
					if (l < 0)
					{
						break;
					}
				}
				if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k)
				{
					ans = min(ans, l + n - r);
				}
				else
				{
					ans = min(ans, l + n - r + 1);
				}
			}
		}
		return ans;
	}
};

int main()
{
	string ss = "cbbac";
	Solution s;
	s.takeCharacters(ss, 1);
}