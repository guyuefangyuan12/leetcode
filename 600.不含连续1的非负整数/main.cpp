#include<vector>
#include<functional>
using namespace std;

class Solution
{
public:
	int findIntegers(int n)
	{
		int size = 0;
		int temp = n;
		while (temp)
		{
			temp = temp >> 1;
			size++;
		}
		vector<vector<vector<int>>>cache(size, vector<vector<int>>(2, vector<int>(2,-1)));
		function<int(int, bool, bool)> dfs = [&](int i, bool is_one, bool is_limit)->int
			{
				int res = 0;
				if (cache[i][int(is_one)][int(is_limit)] != -1)
				{
					return cache[i][int(is_one)][int(is_limit)];
				}
				if (i == 0)
				{
					if (is_one)
					{
						return 1;
					}
					else
					{
						return is_limit && !(n & 1) ? 1 : 2;
					}
				}
				else
				{
					if (is_one)
					{
						res += dfs(i - 1, false, is_limit && !((n >> i) & 1));
					}
					else
					{
						res += dfs(i - 1, false, is_limit && !((n >> i) & 1));
						if (!is_limit || ((n >> i) & 1))
						{
							res += dfs(i - 1, true, true && is_limit);
						}
					}
				}
				cache[i][int(is_one)][int(is_limit)] = res;
				return res;
			};
		return dfs(size - 1, false, true);
	}
};

int main()
{
	Solution s;
	s.findIntegers(8);
}