#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> findPeaks(vector<int>& mountain) 
    {
        vector<int> nums;
        int n = mountain.size();
        for (int i = 1; i < n-1; i++) 
        {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i - 1])
            {
                nums.push_back(mountain[i]);
            }
        }
        return nums;
    }
};