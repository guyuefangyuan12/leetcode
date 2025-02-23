#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!res.empty() && n - i + res.size() > k && res.back() > nums[i]) {
                res.pop_back();
            }
            res.push_back(nums[i]);
        }
        res.resize(k);
        return res;
    }
};

int main() {
    vector<int> nums = { 3,5,2,6 };
    Solution s;
    s.mostCompetitive(nums, 2);
}