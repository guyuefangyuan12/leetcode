#include<vector>
using namespace std;
//对于一个数组，求把所有数到一个数的距离之和最小，则该数为该数组的中位数
//可利用前缀和求解距离之和。
class Solution
{
public:
	long long minimumMoves(vector<int>& nums, int k, int maxChanges)
	{
		long long n = nums.size();
		vector<int> pos;
		int c = 0;
		for (long long i = 0; i < n; i++)
		{
			if (nums[i])
			{
				pos.push_back(i);
				c = max(c, 1);
				if (i > 0 && nums[i - 1] == 1)
				{
					if (i > 1 && nums[i - 2] == 1)
					{
						c = 3;
					}
					else
					{
						c = max(c, 2);
					}
				}
			}
		}
		c = min(k, c);
		if (maxChanges >= k - c)
		{
			return max(c - 1, 0) + (k - c) * 2;
		}
		long left = 0;
		long right = k - 1 - maxChanges;
		vector<long long> sum(n + 1, 0);
		for (long long i = 1; i <= pos.size(); i++)
		{
			sum[i] = sum[i - 1] + pos[i - 1];
		}
		long long Min = INT64_MAX;
		while (right < pos.size())
		{
			int mid = (right + left) / 2;
			long long left_sum = pos[mid] * (mid - left + 1) - sum[mid + 1] + sum[left];
			long long right_sum = sum[right + 1] - sum[mid + 1] - pos[mid] * (right - mid);
			Min = min(Min, right_sum + left_sum);
			right++;
			left++;
		}
		return Min + maxChanges * 2;
	}
};

int main() {
	vector<int> nums = { 1,1,0,1 };
	Solution s;
	s.minimumMoves(nums, 3, 2);
}