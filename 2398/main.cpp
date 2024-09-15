#include<vector>
#include<deque>
using namespace std;

class Solution
{
public:
	int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget)
	{
		int l = 0;
		int r = 0;
		int ans = 0;
		long long sum = 0;
		long long add = 0;
		int n = chargeTimes.size();
		deque<int> q;
		while (r < n)
		{
			if (sum < budget)
			{
				ans = max(ans, r - l);
				add += runningCosts[r];
				sum = add * (r - l + 1) + (q.empty() ? chargeTimes[r] : max(q.front(), chargeTimes[r]));
				while (!q.empty() && q.back() < chargeTimes[r])
				{
					q.pop_back();
				}
				q.push_back(chargeTimes[r]);
				r++;
			}
			else
			{
				add -= runningCosts[l];
				if (q.front() == chargeTimes[l])
				{
					q.pop_front();
				}
				l++;
				if (q.empty())
				{
					sum = 0;
				}
				else
				{
					sum = add * (r - l) + q.front();
				}
			}
		}
		if (sum <= budget)
		{
			ans = max(ans, r - l);
		}
		return ans;
	}
};

int main() {
	vector<int> c = { 250,250,250,250,250,250,250,250,250,250,1,1,1,1,1,1,1,1,1,1 };
	vector<int> r = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	Solution s;
	s.maximumRobots(c, r, 280);
}