#include<vector>
#include<algorithm>
using namespace std;
//¶þ·Ö+Ì°ÐÄ
class Solution {
public:
	int check(vector<int>& diff, int mid) {
		int cnt = 0;
		int total = 0;
		for (int i = 0; i < diff.size(); i++) {
			if (diff[i] <= mid) {
				cnt++;
			}
			else {
				total += (cnt +1)/ 2 ;
				cnt = 0;
			}			
		}
		total += (cnt + 1) / 2;
		return total;
	}

	int minimizeMax(vector<int>& nums, int p) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> diff(n - 1);
		for (int i = 0; i < n - 1; i++) {
			diff[i] = nums[i + 1] - nums[i];
		}
		int left = 0, right = nums[n-1]-nums[0];
		while (left < right) {
			int mid = (left + right) >> 1;
			if (check(diff, mid) >= p) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};

int main() {
	vector<int> nums = { 4,2,1,2 };
	Solution s;
	s.minimizeMax(nums, 1);
}