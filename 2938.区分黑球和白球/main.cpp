#include<string>
#include<queue>
using namespace std;

class Solution
{
public:
	long long minimumSteps(string s)
	{
		long long ans = 0;
		int first = -1;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				if (first == -1)
				{
					first = i;
				}
			}
			else
			{
				if(first!=-1)
				{
					ans = ans + i - first;
					first++;
				}
			}
		}
		return ans;
	}
};

int main()
{
	string s = "0100101";
	Solution ss;
	ss.minimumSteps(s);
}