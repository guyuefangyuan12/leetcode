#include<vector>
using namespace std;

class Solution
{
public:
	int minimumLevels(vector<int>& possible)
	{
		int n = possible.size();
		vector<int> s(n + 1, 0);
		for (int i = 1; i <= n; i++) 
		{
			if(possible[i])
			{
				s[i] = s[i - 1] + 1;
			}
			else 
			{
				s[i] = s[i - 1] - 1;
			}
		}
		for (int i = 1; i < n; i++) 
		{
			if (s[i] * 2 > s[n]) 
			{
				return i;
			}
		}
		return -1;
	}
};