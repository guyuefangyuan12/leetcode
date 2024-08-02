#include<vector> 
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int Max = 0;
        int cnt = 0;
        int left = 0;
        int right = 0;
        while (right < n) 
        {
            if (nums[right] - nums[left] > 2 * k) 
            {
                cnt--;
                left++;
            }
            else 
            {
                right++;
                cnt++;
            }
            Max = max(cnt, Max);
        }
        return Max;
    }
};