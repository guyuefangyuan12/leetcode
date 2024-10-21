#include<vector>
using namespace std;

class Solution
{
public:
	int smallestRangeI(vector<int>& nums, int k)
	{
		int max = nums[0], min = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			max = max > nums[i] ? max : nums[i];
			min = min < nums[i] ? min : nums[i];
		}
		return max - min <= 2 * k ? 0 : max - min - 2 * k;
	}
};