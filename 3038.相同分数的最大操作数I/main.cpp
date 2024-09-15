#include<vector>
using namespace std;

class Solution 
{
public:
    int maxOperations(vector<int>& nums) 
    {
        int n = nums.size();
        int cnt = 1;
        int ans = nums[0] + nums[1];
        for (int i = 3; i < n; i = i + 2)
        {
            if (nums[i] + nums[i - 1] == ans)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        return cnt;
    }
};