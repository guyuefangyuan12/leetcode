#include<vector>
using namespace std;

class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
       int flag = 0;
        int cnt = 0;
        for (int n : nums) 
        {
            if (n == flag) 
            {
                cnt++;
                flag ^= 1;
            }
        }
        return cnt;
    }
};