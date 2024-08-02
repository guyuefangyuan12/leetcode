#include<vector>
#include<numeric>
#include<functional>
using namespace std;

class Solution
{
public:
	int stoneGameVII(vector<int>& stones)
	{
		int n = stones.size();
		function<int(int, int)> dfs = [&](int i, int j)->int
			{
				if (i == j)
				{
					return 0;
				}
				return max(accumulate(stones.begin() + i, stones.begin() + j, 0) - dfs(i, j - 1), accumulate(stones.begin() + i + 1, stones.begin() + j + 1, 0) - dfs(i + 1, j));
			};
		return dfs(0, n - 1);
	}
};

int main() {
	vector<int> stones = { 5,3,1,4,2 };
	Solution s;
	s.stoneGameVII(stones);
}