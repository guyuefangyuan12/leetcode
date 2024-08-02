#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int maximumLength(string s)
	{
		int n = s.size();
		vector<int> len(n);
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || s[i] != s[i - 1])
			{
				len[i] = 1;
			}
			else
			{
				len[i] = len[i - 1] + 1;
			}
		}
		vector<vector<int>> group(26);
		for (int i = 0; i < n; i++) 
		{
			group[s[i] - 'a'].push_back(len[i]);
		}
		int third = -1;
		for (int i = 0; i < 26; i++) {
			sort(group[i].begin(), group[i].end());
			if (group[i].size() >= 3) 
			{
				third = max(third, group[i][group[i].size() - 3]);
			}
		}
		return third;
	}
};
