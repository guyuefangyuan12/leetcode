#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution
{
public:
	vector<int> nextGreaterElements(vector<int>& nums)
	{
		stack<int> s;
		vector<int> Greater(nums);
		int n = nums.size();
		for (int i = n - 1; i >= 0; i--)
		{
			while (!s.empty() && s.top() <= nums[i])
			{
				s.pop();
			}
			if (!s.empty())
			{
				Greater[i] = s.top();
			}
			s.push(nums[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (Greater[i] == nums[i]) 
			{
				int j = 0;
				for ( j = 0; j < i; j++) 
				{
					if (nums[j] > nums[i]) 
					{
						Greater[i] = nums[j];
						break;
					}
				}
				if (i == j) 
				{
					Greater[i] = -1;
				}
			}
		}
		return Greater;
	}
};

int main() {
	vector<int> nums = { 1,2,1 };
	Solution s;
	s.nextGreaterElements(nums);
}