#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int findValueOfPartition(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> cf(n - 1);
		for (int i = 0; i < n - 1; i++) 
		{
			cf[i] = nums[i + 1] - nums[i];
		}
		return *min_element(cf.begin(), cf.end());
	}
};