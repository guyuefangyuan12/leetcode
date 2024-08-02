#include<vector>
using namespace std;

class Solution
{
public:
	vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
	{
		int n = grid.size();
		int k = n * n;
		vector<int> count(k);
		vector<int> ans(2);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				count[grid[i][j] - 1]++;
			}
		}
		for (int i = 0; i < k; i++)
		{
			if (count[i] == 0)
			{
				ans[1] = i + 1;
			}
			else if (count[i] == 2)
			{
				ans[0] = i + 1;;
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> grid = { {1,3},{2,2} };
	Solution s;
	s.findMissingAndRepeatedValues(grid);
}