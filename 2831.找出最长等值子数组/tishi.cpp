#include<vector>
#include<unordered_map>
#include<cmath>
#include<numeric>
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) 
        {
          map[nums[i]].push_back(i);
        }
        int max_length = 1;
        for (auto i : map) 
        {
            int left = 0, right = 0;
            while (right < i.second.size()) 
            {
                if ((i.second[right] - i.second[left] - right + left) <= k) 
                {
                    max_length = max(max_length, right - left + 1);
                    right++;
                }
                else 
                {
                    left++;
                }
            }
        }
        return max_length;
    }
};

int main() {
    vector<int> nums = { 1,2,1 };
    Solution s;
    s.longestEqualSubarray(nums, 0);
}