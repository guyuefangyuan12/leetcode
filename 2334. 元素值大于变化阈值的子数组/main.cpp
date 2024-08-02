#include<vector>
#include<stack>
#include<iostream>
using namespace std;
/*
* 单调栈求解
* 使用单调栈找到第i个元素左右两边第一个小于该元素的下标，将两下标相减再减去1即为以当前元素为最小值的子数组的范围
* 只要该元素小于threshold/k,这该子数组满足要求。
*/
class Solution {
public:
	int validSubarraySize(vector<int>& nums, int threshold) {
		vector<int> leftsmall(nums.size()), rightsmall(nums.size());
		stack<int> s;
		for (int i = 0; i < nums.size(); i++) {
			while (!s.empty() && nums[i] <= nums[s.top()]) {
				s.pop();
			}
			leftsmall[i] = s.empty() ? -1 : s.top();
			s.push(i);
		}
		s = stack<int>{};
		for (int i = nums.size() - 1; i>=0; i--) {
			while (!s.empty() && nums[i] <= nums[s.top()]) {
				s.pop();
			}
			rightsmall[i] = s.empty() ? nums.size() : s.top();
			s.push(i);
		}
		for (int i = 0; i < nums.size(); i++) {
			int k = rightsmall[i] - leftsmall[i] - 1;
			if (nums[i] > threshold / k)
				return k;
		}
		return -1;
	}
};

int main() {
	vector<int> num = { 1,3,4,3,1 };
	Solution s;
	cout << s.validSubarraySize(num, 6);
}