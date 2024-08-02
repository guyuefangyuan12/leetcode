#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution
{
public:
	long long kSum(vector<int>& nums, int k)
	{
		int n = nums.size();
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] > 0)
			{
				sum += nums[i];
			}
			else
			{
				nums[i] = abs(nums[i]);
			}
		}
		sort(nums.begin(), nums.end());
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
		if (k == 1)
		{
			return sum;
		}
		pq.emplace(nums[0], 0);
		long long res = 0;
		while (--k)
		{
			pair<long long, int> temp = pq.top();
			res = temp.first;
			pq.pop();
			if (temp.second < n - 1)
			{
				pq.emplace(temp.first + nums[temp.second + 1], temp.second + 1);
				pq.emplace(temp.first + nums[temp.second + 1] - nums[temp.second], temp.second + 1);
			}
		}
		return sum - res;
	}
};