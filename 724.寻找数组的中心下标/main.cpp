#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int pivotIndex(vector<int>& nums)
	{
		int n = nums.size();
		vector<int>sum(n + 1, 0);
		for (int i = 1; i <= n; i++) 
		{
			sum[i] = sum[i - 1] + nums[i - 1];
		}
		for (int i = 0; i < n; i++) 
		{
			if (sum[i] == sum[n] - sum[i + 1]) 
			{
				return i;
			}
		}
		return -1;
	}
};