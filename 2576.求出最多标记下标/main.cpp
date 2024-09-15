#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
//思路是对的，忘了考虑只用考虑前半部分，超过的不用计算。

class Solution
{
public:
	int maxNumOfMarkedIndices(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<int> pos;
		int n = nums.size();
		int flag = n / 2 + 1;
		int i = 0;
		for (int j = 0; j < n; j++)
		{
			if (nums[j] >= 2 * nums[i])
			{
				i++;
			}
			if (i == flag)
			{
				return 2 * (i - 1);
			}
		}
		return 2 * i;
	}
};

int main() {
	vector<int> nums = { 57,40,57,51,90,51,68,100,24,39,11,85,2,22,67,29,74,82,10,96,14,35,25,76,26,54,29,44,63,49,73,50,95,89,43,62,24,88,88,36,6,16,14,2,42,42,60,25,4,58,23,22,27,26,3,79,64,20,92 };
	Solution s;
	s.maxNumOfMarkedIndices(nums);
}