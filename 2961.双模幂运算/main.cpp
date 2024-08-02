#include<vector>
using namespace std;
//优化方案：使用快速幂进行幂的运算，并在运算过程中取模
class Solution
{
public:
	vector<int> getGoodIndices(vector<vector<int>>& variables, int target)
	{
		int n = variables.size();
		vector<int> ans;
		for (int i = 0; i < n; i++)
		{
			if (variables[i][3] > target)
			{
				int temp = 1;
				for (int j = 0; j < variables[i][1]; j++)
				{
					temp *= variables[i][0] % 10;
					temp %= 10;
				}
				int temp2 = 1;
				for (int j = 0; j < variables[i][3]; j++)
				{
					temp2 *= temp % variables[i][2];
					temp2 %= variables[i][2];
				}
				if (temp2 == target)
				{
					ans.push_back(i);
				}
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> v = { {2,3,3,10},{3,3,3,1},{6,1,1,4} };
	Solution s;
	s.getGoodIndices(v, 2);
}