#include<vector>
using namespace std;

class Solution
{
public:
	vector<int> sortedSquares(vector<int>& nums)
	{
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		vector<int> ans(n, 0);
		for (int i = n - 1; i >= 0; i--)
		{
			if (abs(nums[right]) > abs(nums[left]))
			{
				ans[i] = pow(nums[right], 2);
				right--;
			}
			else
			{
				ans[i] = pow(nums[left], 2);
				left++;
			}
		}
		return ans;
	}
};