#include<vector>
using namespace std;

class Solution 
{
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) 
    {
        int n = distance.size();
        if (start > destination) 
        {
            swap(start, destination);
        }
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i >= start && i < destination) 
            {
                ans += distance[i];
            }
            sum += distance[i];
        }
        return min(ans, sum - ans);
    }
};