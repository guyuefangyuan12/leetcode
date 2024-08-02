#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) 
    {
        int n = nums.size();
        int m = moveFrom.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) 
        {
            if (!map.count(nums[i])) 
            {
                map[nums[i]] = 1;
            }
        }
        for (int i = 0; i < m; i++) 
        {
            if (map.count(moveFrom[i])) 
            {
                map.erase(moveFrom[i]);
                if (!map.count(moveTo[i])) 
                {
                    map[moveTo[i]] = 1;
                }              
            }
        }
        vector<int> ans;
        for (auto& k : map) 
        {
            ans.push_back(k.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};