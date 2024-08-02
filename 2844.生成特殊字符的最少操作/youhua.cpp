#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int minimumOperations(string num)
	{
		int n = num.size();
		unordered_map<char, int> map;
		for (int i = n - 1; i >= 0; i--)
		{
			if (num[i] == '0')
			{
				if (map.count('0'))
				{
					return n - 2 - i;
				}
				map['0'] = i;
			}
			else if (num[i] == '5')
			{
				if (map.count('0'))
				{
					return n - 2 - i;
				}
				map['5'] = i;
			}
			else if (num[i] == '2')
			{
				if (map.count('5'))
				{
					return n - 2 - i;
				}
			}
			else if (num[i] == '7')
			{
				if (map.count('5'))
				{
					return n - 2 - i;
				}
			}
		}
		if (map.count('0'))
		{
			return n - 1;
		}
		return n;
	}
};