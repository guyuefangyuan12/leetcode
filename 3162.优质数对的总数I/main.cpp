#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//枚举倍数
/*
class Solution
{
public:
	long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k)
	{
		int n = nums1.size();
		int m = nums2.size();
		int mx = 0;
		long long ans = 0;
		unordered_map<int, int> map1;
		unordered_map<int, int> map2;
		for (int i = 0; i < n; i++)
		{
			if (nums1[i] % k == 0)
			{
				if (map1.count(nums1[i] / k))
				{
					map1[nums1[i] / k]++;
				}
				else
				{
					map1[nums1[i] / k] = 1;
				}
				mx = max(mx, nums1[i] / k);
			}
		}
		for (int i = 0; i < m; i++)
		{
			if (map2.count(nums2[i]))
			{
				map2[nums2[i]]++;
			}
			else
			{
				map2[nums2[i]] = 1;
			}
		}
		for (auto p : map2)
		{
			for (int i = 1; i * p.first <= mx; i++)
			{
				ans += (long long)map1[i * p.first] * map2[p.first];
			}
		}
		return ans;
	}
};
*/
//枚举因子

class Solution {
public:
	long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k)
	{
		int n = nums1.size();
		int m = nums2.size();
		long long ans = 0;
		unordered_map<int, int> map;
		for (int i = 0; i < n; i++)
		{
			if (nums1[i] % k == 0)
			{
				nums1[i] /= k;
				for (int j = 1; j * j <= nums1[i]; j++)
				{
					if (nums1[i] % j == 0)
					{
						if (map.count(j))
						{
							map[j]++;
						}
						else
						{
							map[j] = 1;
						}
						if (j * j < nums1[i])
						{
							if (map.count(nums1[i] / j))
							{
								map[nums1[i] / j]++;
							}
							else
							{
								map[nums1[i] / j] = 1;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			ans += 1L * map[nums2[i]];
		}
		return ans;
	}
};

int main()
{
	vector<int> nums1 = { 1,3,4 };
	vector<int> nums2 = { 1,3,4 };
	Solution s;
	s.numberOfPairs(nums1, nums2, 1);
}