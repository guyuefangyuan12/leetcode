#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	inline int gcd(int a, int b)
	{
		if (a % b)
		{
			return gcd(b, a % b);
		}
		else
		{
			return b;
		}
	}
	int countBeautifulPairs(vector<int>& nums)
	{
		vector<int> cnt(10);
		int n = nums.size();
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				if (gcd(nums[i] % 10, j) == 1)
				{
					ans += cnt[j];
				}
			}
			int temp = 0;
			for (int j = 3; j >= 0; j--)
			{
				temp = nums[i] / pow(10, j);
				if (temp)
				{
					break;
				}
			}
			cnt[temp]++;
		}
		return ans;
	}
};

int main() {
	vector<int> nums = { 68,8,84,14,88,42,53 };
	Solution s;
	s.countBeautifulPairs(nums);
}