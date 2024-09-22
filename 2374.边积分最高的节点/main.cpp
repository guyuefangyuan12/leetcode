#include<vector>
using namespace std;

class Solution 
{
public:
    int edgeScore(vector<int>& edges) 
    {
        int n = edges.size();
        vector<long long> sum(n, 0);
        int pos = 0;
        long long s = 0;
        for (int i = 0; i < n; i++) 
        {
            sum[edges[i]] += i;
            if (sum[edges[i]] == s)
            {
                if (pos > edges[i])
                {
                    pos = edges[i];
                }
            }
            else if (sum[edges[i]] > s) 
            {
                pos = edges[i];
                s = sum[edges[i]];
            }
        }
        return pos;
    }
};