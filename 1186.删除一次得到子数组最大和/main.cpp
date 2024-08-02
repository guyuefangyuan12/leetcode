#include<vector>
using namespace std;

class Solution
{
public:
	int maximumSum(vector<int>& arr)
	{
		int n = arr.size();
		int Max = INT_MIN;
		vector<vector<int>> dp(n,vector<int>(2,0));
		dp[0][0] = arr[0];
		Max = max(dp[0][0], Max);
		dp[0][1] = 0;
		for (int i = 1; i < n; i++) 
		{
			dp[i][0] = max(arr[i], dp[i - 1][0]+arr[i]);
			Max = max(dp[i][0], Max);
			dp[i][1] = max(dp[i-1][0],dp[i-1][1]+arr[i]);
			Max = max(dp[i][1], Max);
		}
		return Max;
	}
};

int main() 
{
	vector<int> arr = { -50 };
	Solution s;
	s.maximumSum(arr);
}