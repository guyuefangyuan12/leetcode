#include<vector>
#include<unordered_map>
using namespace std;
/// <summary>
/// ˼·1���̶��ζ˵㣬�ҵ�����K�����������������ĺ���С������������˵㣬����һ����Ϊ��
/// ˼·2���ҵ����������K�����������������Ͱ��������K-1����������������������һ����Ϊ��
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