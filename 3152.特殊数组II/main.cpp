#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
	{
		int n = nums.size();
		vector<int> b;
		for (int i = 1; i < n; i++)
		{
			if (nums[i - 1] % 2 + nums[i] % 2 != 1)
			{
				b.push_back(i);
			}
		}
		n = queries.size();
		vector<bool> ans(n, true);
		for (int i = 0; i < n; i++)
		{
			vector<int>::iterator iter = upper_bound(b.begin(), b.end(), queries[i][0]);
			if (iter != b.end() && queries[i][1] >= *iter)
			{
				ans[i] = false;
			}
			else 
			{
				ans[i] = true;
			}
		}
		return ans;
	}
};