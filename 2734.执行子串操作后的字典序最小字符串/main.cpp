#include<string>
#include<vector>
using namespace std;
//优化算法：不需要查找'a'的位置，直接替换不为'a'的字符，直到遇到第一个为'a'的字符
class Solution
{
public:
	string smallestString(string s)
	{
		vector<int> pos;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'a')
			{
				pos.push_back(i);
			}
		}
		if (pos.size() == 0)
		{
			for (int i = 0; i < n; i++)
			{
				s[i] = s[i] - 1;
			}
		}
		else
		{
			if (pos[0] != 0)
			{
				for (int i = 0; i < pos[0]; i++)
				{
					s[i] = s[i] - 1;
				}
			}
			else
			{
				if (pos.size() == 1)
				{
					if (pos[0] != n - 1) 
					{
						for (int i = 1; i < n; i++)
						{
							s[i] = s[i] - 1;
						}
					}
					else 
					{
						s[0] = 'z';
					}
				}
				else
				{
					int end = pos.size();
					for (int i = 1; i < pos.size(); i++)
					{
						if (pos[i] != pos[i - 1]+1)
						{
							end = i;
							break;
						}
					}
					if (end == pos.size())
					{
						if (pos[end - 1] == n - 1)
						{
							s[n - 1] = 'z';
						}
						else
						{
							for (int i = pos[end - 1] + 1; i < n; i++)
							{
								s[i] = s[i] - 1;
							}
						}
					}
					else
					{
						for (int i = pos[end - 1]+1; i < pos[end]; i++)
						{
							s[i] = s[i] - 1;
						}
					}
				}
			}
		}
		return s;
	}
};

int main()
{
	string s = "aba";
	Solution ss;
	ss.smallestString(s);
}