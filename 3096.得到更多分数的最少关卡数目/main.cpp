#include<vector>
using namespace std;

class Solution
{
public:
	int minimumLevels(vector<int>& possible)
	{
		int n = possible.size();
		vector<int> dp(n, 0);
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			temp += possible[i] ? 1 : -1;
		}
		dp[n - 1] = temp;
		for (int i = n - 2; i >= 0; i--)
		{
			if (possible[i + 1])
			{
				dp[i] = dp[i + 1] - 2;
			}
			else
			{
				dp[i] = dp[i + 1] + 2;
			}
		}
		for (int i = 0; i < n - 1; i++)
		{
			if (dp[i] > 0)
			{
				return i + 1;
			}
		}
		return -1;
	}
};

int main() {
	vector<int> nums = { 1,0,1,0 };
	Solution s;
	s.minimumLevels(nums);
}