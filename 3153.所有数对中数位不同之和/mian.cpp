#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
	long long sumDigitDifferences(vector<int>& nums)
	{
		int n = nums.size();
		long long ans = 0;
		int m = to_string(nums[0]).size();
		for (int i = 0; i < m; i++)
		{
			vector<int> cnt(10, 0);
			for (int j = 0; j < n; j++)
			{
				//高效率统计不同数位的个数
				ans += (j - cnt[nums[j] % 10]);
				cnt[nums[j] % 10]++;
				nums[j] /= 10;
			}

			//低效率统计不同数位的个数
			/*
			for (int j = 0; j < 10; j++)
			{
				if (cnt[j] == 0)
				{
					continue;
				}
				for (int k = j + 1; k< 10; k++)
				{
					if (cnt[k] == 0)
					{
						continue;
					}
					long long temp = cnt[j];
					ans += temp * cnt[k];
				}
			}
			*/
		}
		return ans;
	}
};

int main() 
{
	vector<int> nums = { 13,23,12 };
	Solution s;
	s.sumDigitDifferences(nums);
}