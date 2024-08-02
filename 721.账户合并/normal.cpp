#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<functional>
using namespace std;

//给定n个数组，如果两个数组有相同的元素就把这两个数组合并，合并后的数组没有相同元素

class Solution
{
public:
	vector<vector<int>>Merge(vector<vector<int>>& nums)
	{
		int n = nums.size();
		unordered_map<int, vector<int>> map;
		unordered_set<int> num_in;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < nums[i].size(); j++)
			{
				map[nums[i][j]].push_back(i);
			}
		}
		vector<bool> vis(n, false);
		function<void(int, vector<int>&)>dfs = [&](int i, vector<int>& num)
			{
				if (!vis[i])
				{
					vis[i] = true;
					for (int& k : nums[i])
					{
						if (!num_in.count(k))
						{
							num.push_back(k);
							num_in.insert(k);
							for (int& j : map[k])
							{
								dfs(j, num);
							}
						}
					}
				}
			};
		vector<vector<int>>ans;
		for (int i = 0; i < n; i++)
		{
			vector<int> temp;
			dfs(i, temp);
			if (temp.size())
			{
				ans.push_back(temp);
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>>nums = { {1,3,4},{2,5,6},{1,7,8},{9,10,13},{17,19,2} };
	Solution s;
	s.Merge(nums);
}