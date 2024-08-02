#include<vector>
#include<unordered_map>
#include<cmath>
#include<numeric>
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<int>count(m + 1);
        int left = 0, right = k;              
        int Max = 0;
        for (int i = 0; i < k; i++) 
        {
            count[nums[i]]++;
        }
        Max = *max_element(count.begin(), count.end());
        int sum = k;
        int max_length = Max;
        while (right < n) 
        {
            if (sum - Max <= k) 
            {
                max_length = max(Max,max_length);
                count[nums[right++]]++;
                sum++;
            }
            else 
            {
                count[nums[left++]]--;
                sum--;
            }
            Max = *max_element(count.begin(), count.end());           
        }
        if (sum - Max <= k) 
        {
            max_length = max(Max, max_length);
        }
        return max_length;
    }
};

/*
int main() {
    vector<int> nums = { 3,4,2,1 };
    Solution s;
    s.longestEqualSubarray(nums, 2);
}
*/