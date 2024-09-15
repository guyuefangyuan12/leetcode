#include<vector>
using namespace std;

class Solution {
public:
	long long countQuadruplets(vector<int>& nums)
	{
		int n = nums.size();
		int mx = *max_element(nums.begin(), nums.end());
		vector<vector<int>> g(n, vector<int>(mx + 1, 0));
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j < mx + 1; j++)
			{
				g[i][j] = g[i + 1][j];
				if (j < nums[i + 1])
				{
					g[i][j]++;
				}
			}
		}
		vector<vector<int>> l(n, vector<int>(mx + 1, 0));
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < mx + 1; j++)
			{
				l[i][j] = l[i - 1][j];
				if (j > nums[i - 1])
				{
					l[i][j]++;
				}
			}
		}
		long long ans = 0;
		for (int j = 1; j < n - 2; j++)
		{
			for (int k = j + 1; k < n - 1; k++)
			{
				if(nums[j]>nums[k])
				{
					ans += ((long long)l[j][nums[k]] * g[k][nums[j]]);
				}
			}
		}
		return ans;
	}
};

int main() {
	vector<int> nums = { 1,3,2,4,5 };
	Solution s;
	s.countQuadruplets(nums);
}