#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
	string clearDigits(string s)
	{
		string ans;
		int cnt = 0;
		for (char ch : s)
		{
			if (isdigit(ch)) 
			{
				ans.pop_back();
			}
			else 
			{
				ans.push_back(ch);
			}
		}
		return ans;
	}
};