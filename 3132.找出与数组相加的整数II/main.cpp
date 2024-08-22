#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2)
	{
		int n1 = nums1.size();
		int n2 = nums2.size();
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		for (int i = n1 - 1; i >= n1 - 2; i--)
		{
			int k = n2 - 2;
			int d = nums2[n2 - 1] - nums1[i];
			int m = n1 - 1 - i;
			int j = i - 1;
			for (; m <= 2 && k > 0; j--)
			{
				if (nums1[j] + d != nums2[k])
				{
					m++;
				}
				else
				{
					k--;
				}
			}
			if (k < 0)
			{
				return d;
			}
		}
		return nums2[n1 - 3] - nums1[n2 - 1];
	}
};

int main() {
	vector<int> n1 = { 4,20,16,12,8 };
	vector<int> n2 = { 14,18,10 };
	Solution s;
	s.minimumAddedInteger(n1, n2);
}