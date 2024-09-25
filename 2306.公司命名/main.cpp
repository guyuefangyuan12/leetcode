#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
//计算同后缀的交集，然后计算可行的数目

class Solution {
public:
	long long distinctNames(vector<string>& ideas)
	{
		vector<unordered_set<string>>ch(26);
		int n = ideas.size();
		for (string s : ideas)
		{
			ch[s[0] - 'a'].insert(s.substr(1));
		}
		long long ans = 0;
		for (int i = 1; i < 26; i++)
		{
			for (int j = 0; j < i; j++)
			{
				int sum = 0;
				for (string s : ch[i])
				{
					sum += ch[j].count(s);
				}
				ans += (ch[i].size() - sum) * (ch[j].size() - sum);
			}
		}
		return ans * 2;
	}
};

int main()
{
	vector<string> ideas = { "aaa","baa","caa","bbb","cbb","dbb" };
	Solution s;
	s.distinctNames(ideas);
}