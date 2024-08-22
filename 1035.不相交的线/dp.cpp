#include<vector>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution
{
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
	{
		int n1 = nums1.size();
		int n2 = nums2.size();
		unordered_map<int, vector<int>> map;
		for (int i = 0; i < n1; i++)
		{
			map[nums1[i]].push_back(i);
		}
		vector<vector<int>> dp(n2 + 1, vector<int>(n1 + 1, 0));
		for (int i = n2 - 1; i >= 0; i--)
		{
			for (int j = 0; j <= n1; j++)
			{
				for (int n : map[nums2[i]])
				{
					if (n > j - 1)
					{
						dp[i][j] = dp[i + 1][n] + 1;
						break;
					}
				}
				dp[i][j] = max(dp[i][j], dp[i + 1][j]);
			}
		}
		return dp[0][0];
	}
};
int main() 
{
	vector<int> n1 = { 3 };
	vector<int> n2 = { 3,3,2 };
	Solution s;
	s.maxUncrossedLines(n1, n2);
}