#include<string>
using namespace std;

class Solution {
public:
	int longestContinuousSubstring(string s)
	{
		int n = s.size();
		int l = 0;
		int r = 0;
		int ans = 0;
		while (r < n)
		{
			if (r == l)
			{
				r++;
			}
			else
			{
				if (s[r] == s[r - 1] + 1)
				{
					r++;
				}
				else
				{
					ans = max(ans, r - l);
					l = r;
				}
			}
		}
		ans = max(ans, r - 1);
		return ans;
	}
};

int main() {
	string s = "abacaba";
	Solution ss;
	ss.longestContinuousSubstring(s);
}