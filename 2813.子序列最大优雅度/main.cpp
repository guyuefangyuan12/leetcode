#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
public:
	long long findMaximumElegance(vector<vector<int>>& items, int k)
	{
		sort(items.begin(), items.end(), [](vector<int>& x1, vector<int>& x2) {return x1[0] > x2[0]; });
		int n = items.size();
		unordered_map<int, int> map;
		stack<int> s;
		long long ans = 0, total_pofit = 0;
		for (int i = 0; i < k; i++)
		{
			total_pofit += items[i][0];
			if (map.count(items[i][1])) 
			{
				s.push(items[i][0]);
			}
			else 
			{
				map[items[i][1]] = 1;
			}
		}
		ans = total_pofit + map.size() * map.size();
		for (int i = k; i < n; i++)
		{
			if (s.empty())
			{
				break;
			}
			if (map.count(items[i][1])) 
			{
				continue;
			}
			else 
			{
				map[items[i][1]] = 1;
				total_pofit = total_pofit-s.top()+items[i][0];
				s.pop();
				ans = max(ans, total_pofit + (long long)map.size() * (long long)map.size());
			}
		}
		return ans;
	}
};

int main() 
{
	vector<vector<int>> items = { {1,2},{10,1} };
	Solution s;
	s.findMaximumElegance(items, 1);
}