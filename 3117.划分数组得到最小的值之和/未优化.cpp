#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;
//ʧ�ܷ�����dp�Ĺؼ��Ƕ�ÿһ��i���м�¼��������һ�εݹ��ｫi���ӻ���ٶ��
class Solution
{
public:
	int minimumValueSum(vector<int>& nums, vector<int>& andValues)
	{
		int n = nums.size();
		int m = andValues.size();
		vector<vector<int>> cache(m + 1, vector<int>(n + 1, -2));
		function<int(int, int)> dfs = [&](int i, int pos)->int
			{
				if (cache[i][pos] != -2)
				{
					return cache[i][pos];
				}
				int ans = INT_MAX;
				if (i == m)
				{
					if (pos == n)
					{
						cache[i][pos] = 0;
						return 0;
					}
					else
					{
						cache[i][pos] = -1;
						return -1;
					}
				}
				if (pos >= n)
				{
					cache[i][pos] = -1;
					return -1;
				}
				int temp = nums[pos];
				bool flag = false;
				if (temp == andValues[i])
				{
					int ret = dfs(i + 1, pos + 1);
					if (ret != -1)
					{
						ans = min(ans, nums[pos] + ret);
						flag = true;
					}
				}
				for (int j = pos + 1; j < n; j++)
				{
					temp &= nums[j];
					if (temp == andValues[i])
					{
						int ret = dfs(i + 1, j + 1);
						if (ret != -1)
						{
							flag = true;
							ans = min(ans, nums[j] + ret);
						}
					}
					else if (flag)
					{
						break;
					}
				}
				if (!flag)
				{
					cache[i][pos] = -1;
					return -1;
				}
				cache[i][pos] = ans;
				return ans;
			};
		return dfs(0, 0);
	}
};