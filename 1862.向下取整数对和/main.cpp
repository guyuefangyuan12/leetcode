#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
using namespace std;
//前缀和，通过计算一个区间内的数字个数，降低数据查询的时间复杂度
class Solution {
public:
	long sumOfFlooredPairs(vector<int>& nums) {
		long sum = 0;
		int n = 100000;
		long res = 1000000007;
		int Max = 0;
		vector<int> cnt(n+1);
		for (int i = 0; i < nums.size(); i++) {
			cnt[nums[i]]++;
			Max = max(Max, nums[i]);
		}
		vector<int> pre(Max+1);
		for (int i = 1; i <= Max; i++) {
			pre[i] = pre[i - 1] + cnt[i];
		}
		for (int i = 1; i < Max; i++) {
			if (cnt[i]) {
				for (int j = 1; j * i <= Max; j++) {
					sum += (long)cnt[i] * j * (pre[min(Max, (j + 1) * i - 1)] - pre[ j * i - 1 ]);
				}
			}
		}
		return sum % res;
	}
};


int main() {
	vector<int> num = { 4,3,4,3,5 };
	Solution s;
	s.sumOfFlooredPairs(num);
}