#include<string>
#include<unordered_map>
using namespace std;
//维护每种字符连续出现长度，取里面第三长的字符长度
class Solution
{
public:
	int maximumLength(string s)
	{
		unordered_map<string, int> map;
		string temp;
		int n = s.size();
		int first = 0;
		int last = 0;
		int Max = -1;
		while (last < n)
		{
			if (s[first] == s[last])
			{
				last++;
			}
			else
			{
				for (int i = 0; i < last - first; i++)
				{
					temp.push_back(s[first]);
					if (map.count(temp))
					{
						map[temp] += last - first - i;
					}
					else
					{
						map[temp] = last - first - i;
					}
				}
				temp.clear();
				first = last;
			}
		}
		for (int i = 0; i < last - first; i++)
		{
			temp.push_back(s[first]);
			if (map.count(temp))
			{
				map[temp] += last - first - i;
			}
			else
			{
				map[temp] = last - first - i;
			}
		}
		for (auto i : map)
		{
			if (i.second >= 3)
			{
				Max = max(Max, (int)i.first.size());
			}
		}
		return Max;
	}
};

int main() {
	string s = "";
	Solution ss;
	ss.maximumLength(s);
}