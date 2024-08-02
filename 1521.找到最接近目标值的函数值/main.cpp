#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int closestToTarget(vector<int>& arr, int target) {
		vector<int> nums;
		int n = arr.size();
		int Min = abs(arr[0] - target);
		nums.push_back(arr[0]);
		for (int i = 1; i < n; i++) {
			int m = nums.size();
			vector<int> nums_new;
			for (int j = 0; j < m; j++) {
				int temp = nums[j] & arr[i];
				Min = min(Min, abs(temp - target));
				if (find(nums_new.begin(), nums_new.end(), temp) == nums_new.end()) {
					nums_new.push_back(temp);
				}
			}
			nums_new.push_back(arr[i]);
			Min = min(Min, abs(arr[i] - target));
			nums = nums_new;
		}
		return Min;
	}
};

int main() {
	vector<int> arr = { 10,15,7 };
	Solution s;
	s.closestToTarget(arr, 2);
}