#include<vector>
#include<algorithm>
#include<ranges>
using namespace std;

class Solution
{
public:
	vector<int> numberGame(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> ans;
		ranges::sort(nums);
		for (int i = 0; i < n; i += 2)
		{
			ans.push_back(nums[i + 1]);
			ans.push_back(nums[i]);
		}
		return ans;
	}
};