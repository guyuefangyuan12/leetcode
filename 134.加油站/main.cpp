#include<vector>
using namespace std;

class Solution
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		int n = gas.size();
		int ans = 0;
		int sum = 0;
		int mn = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			sum += gas[i] - cost[i];
			if (sum < mn)
			{
				mn = sum;
				ans = i;
			}
		}
		return sum >= 0 ? (ans + 1) % n : -1;
	}
};

int main() {
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	Solution s;
}