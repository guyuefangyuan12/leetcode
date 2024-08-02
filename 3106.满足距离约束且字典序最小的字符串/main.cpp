#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
	string getSmallestString(string s, int k)
	{
		int n = s.size();
		bool flag = false;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (min(s[i] - 'a', 'z' + 1 - s[i]) <= k)
			{				
				k -= min(s[i] - 'a', 'z' + 1 - s[i]);
				s[i] = 'a';
			}
			else 
			{
				s[i] = s[i] - k;
				break;
			}
		}
		return s;
	}
};