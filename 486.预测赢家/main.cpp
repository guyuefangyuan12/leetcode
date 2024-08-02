#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
	int total(vector<int>& nums, int start, int end, int turn) {
		if (start == end) {
			return nums[start] * turn;
		}
		int	totalstart = total(nums, start + 1, end, (turn * -1))+nums[start]*turn;
		int	totalend = total(nums, start , end-1, (turn * -1)) + nums[end]*turn;
		return max(totalstart*turn,totalend*turn)*turn;
	}

	bool predictTheWinner(vector<int>& nums) {
		if (total(nums, 0, nums.size()-1, 1) >= 0)
			return true;
		else return false;
	}
};

int main() {
	vector<int> nums = { 1,5,2 };
	Solution s;
	s.predictTheWinner(nums);
}