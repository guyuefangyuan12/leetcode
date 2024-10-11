#include<vector>
using namespace std;

//���ʹ��O(n^2)���Ӷȼ��������������İ�λ��
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
//���Ӷ��Ż�
//��ΪOR��������ԣ�����һ�����󲻻��С�����Ե��ڲ�ѭ��OR֮�󲻱�ʱ�Ϳ����˳�ѭ��
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