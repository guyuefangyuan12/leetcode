#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
//优化方法：先处理queries，然后在从后往前遍历heights，每次遍历时对queries进行判断，符合条件则更新ans
class Solution
{
public:
	vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries)
	{
		int n = heights.size();
		vector<int> left(n, -1);
		stack<pair<int, int>> s;
		unordered_map<long long, int>map;
		for (int i = 0; i < n; i++)
		{
			while (!s.empty())
			{
				if (heights[i] > s.top().second)
				{
					left[s.top().first] = i;
					s.pop();
				}
				else
				{
					break;
				}
			}
			s.push(make_pair(i, heights[i]));
		}
		n = queries.size();
		vector<int> ans(n, -1);
		for (int i = 0; i < n; i++)
		{
			int a = queries[i][0];
			int b = queries[i][1];
			if (a == b)
			{
				ans[i] = b;
				continue;
			}
			if (b < a)
			{
				swap(a, b);
			}
			if (left[a] == -1)
			{
				ans[i] = -1;
				map[(a << 16) | b] = -1;
				continue;
			}
			while (heights[b] <= heights[a])
			{
				if (map.count((a << 16) | b))
				{
					b = map[(a << 16) | b];
					break;
				}
				else
				{
					b = left[b];
					if (b == -1)
					{
						break;
					}
				}
			}
			map[(a << 16) | queries[i][1]] = b;
			ans[i] = b;
		}
		return ans;
	}
};

int main() {
	vector<int> heights = { 6,4,8,5,2,7 };
	vector<vector<int>> queries = { {0,1} ,{0,3},{3,4} };
	Solution s;
	s.leftmostBuildingQueries(heights, queries);
}