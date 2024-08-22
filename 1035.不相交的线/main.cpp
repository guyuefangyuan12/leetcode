#include<vector>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution
{
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
	{
		int n1 = nums1.size();
		int n2 = nums2.size();
		int cnt = 0;
		unordered_map<int, vector<int>> map;
		for (int i = 0; i < n1; i++)
		{
			map[nums1[i]].push_back(i);
		}
		function<int(int, int)> dfs = [&](int i, int j)->int
			{
				if (i == n2)
				{
					return 0;
				}
				if (j == n1 - 1)
				{
					return 0;
				}
				int ans = 0;
				for (int n : map[nums2[i]])
				{
					if (n > j)
					{
						ans = dfs(i + 1, n) + 1;
						break;
					}
				}
				ans = max(ans, dfs(i + 1, j));
				return ans;
			};
		return dfs(0, -1);
	}
};