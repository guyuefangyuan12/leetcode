#include<vector>
using namespace std;

//如何使用O(n^2)复杂度计算出所有子数组的按位或
/*
class Solution
{
public:
	int minimumDifference(vector<int>& nums, int k)
	{
		int n = nums.size();
		int diff = INT_MAX / 2;
		for (int i = 0; i < n; i++)
		{
			diff = min(abs(nums[i] - k), diff);
			for (int j = i - 1; j >= 0; j--)
			{
				nums[j] |= nums[i];
				diff = min(abs(nums[j] - k), diff);
			}
		}
		return diff;
	}
};
*/
//复杂度优化
//因为OR运算的特性，或上一个数后不会减小，所以当内层循环OR之后不变时就可以退出循环
class Solution
{
public:
	int minimumDifference(vector<int>& nums, int k)
	{
		int n = nums.size();
		int diff = INT_MAX / 2;
		for (int i = 0; i < n; i++)
		{
			diff = min(abs(nums[i] - k), diff);
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[j] != (nums[j] | nums[i]))
				{
					nums[j] |= nums[i];
					diff = min(abs(nums[j] - k), diff);
				}
				else 
				{
					break;
				}
			}
		}
		return diff;
	}
};