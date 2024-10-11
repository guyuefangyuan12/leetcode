#include<vector>
#include<stack>
using namespace std;
/*
窗口更新原则：
1.当移动右边界，发现窗口的OR值大于K时，更新一次diff,然后移动左边界，减小窗口值,同时更新diff
当窗口值小于K时，就可以移动右边界了
*/
class Solution
{
public:
	int minimumDifference(vector<int>& nums, int k)
	{
		int n = nums.size();
		int ans = INT_MAX / 2;
		int left = 0;
		int right = 0;
		int bottom = 0;
		int right_or = 0;
		for (; right < n; right++)
		{
			right_or |= nums[right];
			while (right >= left && (nums[left] | right_or) > k) 
			{
				ans = min(ans, (nums[left] | right_or) - k);
				if (bottom <= left) 
				{
					for (int i = right - 1; i > left; i--) 
					{
						nums[i] |= nums[i + 1];
					}
					bottom = right;
					right_or = 0;
				}
				left++;
			}
			if (left <= right) 
			{
				ans = min(ans, k - (nums[left] | right_or));
			}
		}
		return ans;
	}
};