#include<vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int>& nums)
	{
		int n = nums.size();
		int left = 0;
		int cnt = 0;
		while (left < n - 3)
		{
			if (!nums[left])
			{
				cnt++;
				nums[left] ^= 1;
				nums[left + 1] ^= 1;
				nums[left + 2] ^= 1;
			}
			left++;
		}
		if (nums[left] == nums[left + 1] && nums[left] == nums[left + 2])
		{
			return cnt + (nums[left] ^ 1);
		}
		return -1;
	}
};

int main() {
	vector<int>nums = { 1,0,0,1,1,1,0,1,1,1 };
	Solution s;
	s.minOperations(nums);
}