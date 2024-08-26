#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
using namespace std;

//当s确定时，add也会被确定，所以可以只记忆一个参数
class Solution
{
public:
	int popcount(int m)
	{
		int count = 0;
		while (m)
		{
			m = m & (m - 1);
			count++;
		}
		return count;
	}
	bool canPartitionKSubsets(vector<int>& nums, int k)
	{
		int n = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k != 0)
		{
			return false;
		}
		sum /= k;
		sort(nums.begin(), nums.end());
		if (nums[n - 1] > sum)
		{
			return false;
		}
		auto dfs = [&](auto&& dfs, int add, int s)->bool
			{
				int num = popcount(s);
				if (s == (1 << n) - 1)
				{
					return true;
				}
				if (add + nums[0] > sum) {
					return false;
				}
				for (int j = 0; j < n; j++)
				{
					if (j != 0 && nums[j] == nums[j - 1] && (((s >> j - 1) & 1) == 0))
					{
						continue;
					}
					if ((s >> j & 1) == 0)
					{
						int temp = add + nums[j];
						if (temp == sum)
						{
							if (dfs(dfs, 0, s | (1 << j)))
							{
								return true;
							}
						}
						else if (temp < sum)
						{
							if (dfs(dfs, temp, s | (1 << j)))
							{
								return true;
							}
						}
						else
						{
							return false;
						}
					}
				}
				return false;
			};
		return dfs(dfs, 0, 0);
	}
};

int main() {
	vector<int> nums = { 4,3,2,3,5,2,1 };
	Solution s;
	s.canPartitionKSubsets(nums, 4);
}