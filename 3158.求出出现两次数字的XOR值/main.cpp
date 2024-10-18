#include<vector>
#include<unordered_set>
using namespace std;

class Solution 
{
public:
    int duplicateNumbersXOR(vector<int>& nums)
    {
        unordered_set<int> s;
        int ans = 0;
        for (int& i : nums) 
        {
            if (s.count(i)) 
            {
                ans ^= i;
            }
            else 
            {
                s.insert(i);
            }
        }
        return ans;
    }
};