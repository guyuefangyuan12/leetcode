#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int kthLargestValue(vector<vector<int>>& matrix, int k)
	{
		vector<int> nums;
		int m = matrix.size();
		int n = matrix[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0)
				{
					if (j == 0)
					{
						matrix[i][j] = matrix[i][j];
					}
					else
					{
						matrix[i][j] ^= matrix[i][j - 1];
					}
				}
				else
				{
					if (j == 0)
					{
						matrix[i][j] ^= matrix[i - 1][j];
					}
					else
					{
						matrix[i][j] ^= matrix[i][j - 1];
						matrix[i][j] ^= matrix[i - 1][j];
						matrix[i][j] ^= matrix[i - 1][j - 1];
					}
				}
				nums.push_back(matrix[i][j]);
			}
		}
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};

int main()
{
	vector<vector<int>> m = { {5,2},{1,6} };
	Solution s;
	s.kthLargestValue(m, 3);
}