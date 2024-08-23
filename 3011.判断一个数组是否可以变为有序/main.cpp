#include<vector>
using namespace std;

class Solution
{
public:
	bool canSortArray(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> pos(n, 0);
		int m = 0;
		int up1 = 0;
		int up2 = 0;
		for (int i = 0; i < n; i++)
		{
			int temp = nums[i];
			while (temp)
			{
				if (temp & 1)
				{
					pos[i]++;
				}
				temp = temp >> 1;
			}
			if (i == 0)
			{
				up1 = nums[i];
			}
			else
			{
				if (pos[i - 1] != pos[i])
				{
					up2 = up1;
					up1 = 0;
				}
				up1 = max(up1, nums[i]);
			}			
			if (up2 >= nums[i])
			{				
				return false;
			}
		}
		return true;
	}
};

int main() {
	vector<int>nums = { 2,28,9 };
	Solution s;
	s.canSortArray(nums);
}