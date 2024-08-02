#include<vector>
#include<unordered_map>

using namespace std;
class Solution
{
public:
	vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_map<int, int> n1;
		unordered_map<int, int> n2;
		for (int n : nums1)
		{
			if (n1.count(n))
			{
				n1[n]++;
			}
			else
			{
				n1[n] = 1;
			}
		}
		for (int n : nums2)
		{
			if (n2.count(n))
			{
				n2[n]++;
			}
			else
			{
				n2[n] = 1;
			}
		}
		vector<int> ans(2, 0);
		for (int n : nums1)
		{
			if (n2.count(n))
			{
				ans[0]++;
			}
		}

		for (int n : nums2)
		{
			if (n1.count(n))
			{
				ans[1]++;
			}
		}
		return ans;
	}
};

int main() 
{
	vector<int> nums1 = { 10,30,16,18 };
	vector<int>nums2 = { 23,30,30,6,10,26,9,27,6,16,18,10,27,2,20,7,16 };
	Solution s;
	s.findIntersectionValues(nums1, nums2);
}