#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

class Solution
{
public:
	long long minimumTime(vector<int>& time, int totalTrips)
	{
		sort(time.begin(), time.end());
		long long l = 0;
		long long r = LONG_MAX;
		function<bool(long long mid)> check = [&](long long mid)->bool
			{
				long long sum = 0;
				for (int t : time)
				{
					sum += mid / t;
					if (sum >= totalTrips)
					{
						return true;
					}
				}
				return false;
			};
		while (l != r - 1)
		{
			long long mid = (l + r) >> 1;
			check(mid) ? r = mid : l = mid;
		}
		return r;
	}
};

int main() {
	vector<int> t = { 1,2,3 };
	Solution s;
	s.minimumTime(t, 5);
}