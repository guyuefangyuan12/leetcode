#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int numberOfPoints(vector<vector<int>>& nums)
	{
		int n = nums.size();
		sort(nums.begin(), nums.end(), [&](vector<int>& a, vector<int>& b)->bool {
			return a[0] < b[0];
			});
		vector<int> temp = { nums[0][0] ,nums[0][1] };
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			if (nums[i][0] >= temp[0] && nums[i][0] <= temp[1])
			{
				if (nums[i][1] > temp[1])
				{
					temp[1] = nums[i][1];
				}
			}
			else
			{
				ans = ans + temp[1] - temp[0] + 1;
				temp[0] = nums[i][0];
				temp[1] = nums[i][1];
			}
		}
		ans = ans + temp[1] - temp[0] + 1;
		return ans;
	}
};