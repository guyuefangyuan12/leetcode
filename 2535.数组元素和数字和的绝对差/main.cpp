#include<vector>
using namespace std;

class Solution
{
public:
	int differenceOfSum(vector<int>& nums)
	{
		int n = nums.size();
		int sum = 0;
		for (int i : nums)
		{
			sum += i;
			while (i)
			{
				sum -= i % 10;
				i /= 10;
			}
		}
		return sum;
	}
};