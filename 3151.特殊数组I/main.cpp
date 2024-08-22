#include<vector>
using namespace std;

class Solution
{
public:
	bool isArraySpecial(vector<int>& nums)
	{
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] % 2 + nums[i] % 2 != 1)
			{
				return false;
			}
		}
		return true;
	}
};

int main() {
	vector<int> nums = { 2,1,4 };
	Solution s;
	s.isArraySpecial(nums);
}