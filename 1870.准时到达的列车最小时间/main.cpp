#include<vector>
#include<functional>
using namespace std;

class Solution
{
public:
	int minSpeedOnTime(vector<int>& dist, double hour)
	{
		int n = dist.size();
		function<bool(int)> check = [&](int v)->bool
			{
				double sum = 0;
				for (int i = 0; i < n - 1; i++)
				{
					sum += dist[i] % v ? dist[i] / v + 1 : dist[i] / v;
					if (sum > hour)
					{
						return false;
					}
				}
				sum += dist[n - 1] / (v * 1.0);
				return sum > hour ? false : true;
			};
		int l = 0;
		int r = 10000001;
		while (l != r - 1)
		{
			int mid = (l + r) >> 1;
			check(mid) ? r = mid : l = mid;
		}
		return r == 10000001 ? -1 : r;
	}
};

int main()
{
	vector<int> dist = { 1,3,2 };
	Solution s;
	s.minSpeedOnTime(dist, 2.7);
}