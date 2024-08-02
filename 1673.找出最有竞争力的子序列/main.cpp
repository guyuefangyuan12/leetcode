#include<vector>
using namespace std;

class Solution {
public:
	vector<int> mostCompetitive(vector<int>& nums, int k)
	{
		vector<int> subnum;
		vector<int>::iterator n = nums.begin();
		for (int i = 0; i < k; i++)
		{
			n = min_element(n, (nums.end() - k + i + 1)) + 1;
			int min_num = *(n-1);
			subnum.push_back(min_num);
		}
		return subnum;
	}
};
/*
int main() {
	vector<int> nums;
	for (int i = 0; i < 100000; i++) {
		nums.push_back(0);
	}
	Solution s;
	s.mostCompetitive(nums, 5000);
}
*/