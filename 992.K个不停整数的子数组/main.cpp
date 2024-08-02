#include<vector>
#include<unordered_map>
using namespace std;
/// <summary>
/// 思路1：固定游端点，找到包含K个整数的最大子数组的和最小子数组数的左端点，两者一减即为答案
/// 思路2：找到包含最多有K个整数的子数组数和包含最多有K-1个整数的子数组数，两者一减即为答案
/// </summary>
class Solution {
public:
	int subarraysWithKDistinct(vector<int>& nums, int k) {
		int count = 0;
		int n = nums.size();
		vector<int> left(n);
		unordered_map<int, int> map;
		for (int i = 0, j = 0; i < n ; i++) {
			if (map.count(nums[i])) {
				map[nums[i]]++;
			}
			else {
				map[nums[i]] = 1;
			}
			while (map.size() == k) {
				int x = j++;
				map[nums[x]]--;
				if (map[nums[x]] == 0) {
					map.erase(nums[x]);
				}
			}
			left[i] = j - 1;
		}
		map.clear();
		for (int i = 0, j = 0; i < n ; i++) {
			if (map.count(nums[i])) {
				map[nums[i]]++;
			}
			else {
				map[nums[i]] = 1;
			}
			while (map.size() > k) {
				int x = j++;
				map[nums[x]]--;
				if (map[nums[x]] == 0) {
					map.erase(nums[x]);
				}
			}
			if (map.size() == k)
				count += left[i] - j + 1;
		}
		return count;
	}
};

int main() {
	vector<int>nums = { 1,2,1,3,4 };
	Solution s;
	s.subarraysWithKDistinct(nums, 3);
}