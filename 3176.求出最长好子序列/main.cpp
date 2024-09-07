#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int maximumLength(vector<int>& nums, int k)
	{
		int n = nums.size();
		unordered_map<int, vector<int>>dp;
		vector<vector<int>> record(k + 1, vector<int>(3, 0));
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			auto& f = dp[nums[i]];
			f.resize(k + 1);
			for (int j = 0; j < k + 1; j++)
			{
				if (j)
				{
					f[j] = max(f[j], nums[i] != record[j - 1][0] ? record[j - 1][1] : record[j - 1][2]) + 1;
				}
				else
				{
					f[j]++;
				}
				if (f[j] > record[j][1])
				{
					record[j][2] = record[j][1];
					record[j][0] = nums[i];
					record[j][1] = f[j];
				}
				else if (f[j] > record[j][2])
				{
					record[j][2] = f[j];
				}
				ans = max(f[j], ans);
			}
		}
		return ans;
	}
};

int main() {
	vector<int> nums = { 2 };
	Solution s;
	s.maximumLength(nums, 0);
}