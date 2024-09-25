#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
	long long maximumSubsequenceCount(string text, string pattern)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		long long ans = 0;
		for (char ch : text)
		{
			if (ch == pattern[1])
			{
				ans += cnt1;
				cnt2++;
			}
			if (ch == pattern[0])
			{
				cnt1++;
			}
		}
		return ans += max(cnt1, cnt2);
	}
};