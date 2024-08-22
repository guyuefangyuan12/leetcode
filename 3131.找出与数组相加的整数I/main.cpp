#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

class Solution
{
public:
	int addedInteger(vector<int>& nums1, vector<int>& nums2)
	{
		return *max_element(nums1.begin(), nums1.end()) - *max_element(nums2.begin(), nums2.end());
	}
};