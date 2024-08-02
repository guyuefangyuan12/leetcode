#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
	{
		int n = difficulty.size();
		vector<pair<int, int>> dp(n);
		for (int i = 0; i < n; i++)
		{
			dp[i] = make_pair(difficulty[i], profit[i]);
		}
		sort(dp.begin(), dp.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second; });
		sort(worker.begin(), worker.end(), greater<int>());
		int pos = 0;
		int ans = 0;
		for (int i : worker)
		{
			for (int j = pos; j < n; j++) 
			{
				if (i >= dp[j].first) 
				{
					ans += dp[j].second;
					pos = j;
					break;
				}
			}
		}
		return ans;
	}
};

int main() 
{
	vector<int> n1 = { 2,4,6,8,10 };
	vector<int> n2 = { 10,20,30,40,50 };
	vector<int> n3 = { 4,5,6,7 };
	Solution s;
	s.maxProfitAssignment(n1,n2,n3);
}