#include<vector>
using namespace std;

class Solution
{
public:
	int timeRequiredToBuy(vector<int>& tickets, int k)
	{
		int n = tickets.size();
		int ans = 0;
		for (int i = 0; i <= k; i++)
		{
			ans += tickets[i] > tickets[k] ? tickets[k] : tickets[i];
		}
		for (int i = k + 1; i < n; i++)
		{
			ans += tickets[i] > tickets[k] - 1 ? tickets[k] - 1 : tickets[i];
		}
		return ans;
	}
};