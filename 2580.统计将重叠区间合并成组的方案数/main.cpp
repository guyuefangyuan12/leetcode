#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution 
{
public:
    int countWays(vector<vector<int>>& ranges) 
    {
        sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0]; });
        int Max = ranges[0][1];
        int cnt = 1;
        for (auto& i : ranges) 
        {
            if (i[0] > Max) 
            {
                cnt++;
            }
            Max = max(Max, i[1]);
        }
        int ans = 1;
        long a = 2;
        while (cnt) 
        {
            if (cnt & 1) 
            {
                ans = ans * a % 1000000007;
            }
            a = a * a % 1000000007;
            cnt /= 2;
        }
        return ans;
    }
};

int main() 
{
    vector<vector<int>> ranges = { {1,3},{10,20},{2,5},{4,8} };
    Solution s;
    s.countWays(ranges);
}