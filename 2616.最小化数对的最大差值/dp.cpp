#include<vector>
#include<algorithm>
using namespace std;
//¶þ·Ö+dp
class Solution {
public:
	int minimizeMax(vector<int>& nums, int p) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> diff(n);
		vector<int> dp(n);
		for (int i = 1; i < n; i++) {
			diff[i] = nums[i] - nums[i - 1];
		}
		int left = 0;
		int right = nums[n - 1] - nums[0];
		dp[0] = 0;
		while (left < right) {
			int mid = (left + right) >> 1;
			dp[1] = diff[1] > mid ? 0 : 1;
			for (int i = 2; i < n; i++) {
				if (diff[i] > mid) {
					dp[i] = dp[i - 1];
				}
				else {
					if (dp[i - 2] + 1 == p) {
						dp[n-1] = p;
						break;
					}
					dp[i] = max(dp[i - 1], dp[i - 2] + 1);
				}
			}
			if (dp[n - 1] < p) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left;
	}
};
