#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        vector<int> diff(101, 0);
        for (auto i : nums) 
        {
            diff[i[0]]++;
            diff[i[1]]--;
        }
        int ans = 0;
        int temp = 0;
        for (int i : diff)
        {
            temp += i;
            if (temp > 0) 
            {
                ans++;
            }
        }
        return ans;
    }
};