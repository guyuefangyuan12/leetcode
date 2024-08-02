#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) 
    {
        int n = nums.size();
        vector<int> c;
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + indexDifference; j < n; j++) 
            {
                if (abs(nums[i] - nums[j]) >= valueDifference) 
                {
                    c.push_back(i);
                    c.push_back(j);
                    break;
                }
            }
            if (c.size() > 0)
            {
                break;
            }
        }
        if (c.size() == 0)
        {
            c.push_back(-1);
            c.push_back(-1);
        }
        return c;
    }
};

int main() {
    vector<int> nums = { 5,1,4,1 };
    Solution s;
    s.findIndices(nums, 2, 4);
}