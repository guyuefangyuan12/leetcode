#include<vector>
#include<stack>
using namespace std;
/*
���ڸ���ԭ��
1.���ƶ��ұ߽磬���ִ��ڵ�ORֵ����Kʱ������һ��diff,Ȼ���ƶ���߽磬��С����ֵ,ͬʱ����diff
������ֵС��Kʱ���Ϳ����ƶ��ұ߽���
*/
class Solution
{
public:
	int minimumDifference(vector<int>& nums, int k)
	{
		int n = nums.size();
		int ans = INT_MAX / 2;
		int left = 0;
		int right = 0;
		int bottom = 0;
		int right_or = 0;
		for (; right < n; right++)
		{
			right_or |= nums[right];
			while (right >= left && (nums[left] | right_or) > k) 
			{
				ans = min(ans, (nums[left] | right_or) - k);
				if (bottom <= left) 
				{
					for (int i = right - 1; i > left; i--) 
					{
						nums[i] |= nums[i + 1];
					}
					bottom = right;
					right_or = 0;
				}
				left++;
			}
			if (left <= right) 
			{
				ans = min(ans, k - (nums[left] | right_or));
			}
		}
		return ans;
	}
};