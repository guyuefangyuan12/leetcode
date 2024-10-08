#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
	{
		stations.push_back({ target,0 });
		priority_queue<int> q;
		int n = stations.size();
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			while (startFuel < stations[i][0])
			{
				if (q.empty())
				{
					return -1;
				}
				startFuel += q.top();
				q.pop();
				cnt++;
			}
			q.push(stations[i][1]);
		}
		return cnt;
	}
};

int main() {
	vector<vector<int>> sta = { {10,60},{20,30},{30,30},{60,40} };
	Solution s;
	s.minRefuelStops(100, 10, sta);
}