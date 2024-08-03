#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) 
    {
        int n = points.size();
        vector<vector<int>> count(26,vector<int>(2,INT_MAX));
        for (int i = 0; i < n; i++) 
        {
            int temp = max(abs(points[i][0]), abs(points[i][1]));
            if (temp < count[s[i] - 'a'][0]) 
            {
                count[s[i] - 'a'][1] = count[s[i] - 'a'][0];
                count[s[i] - 'a'][0] = temp;
            }
            else if (temp < count[s[i] - 'a'][1])
            {
                count[s[i] - 'a'][1] = temp;
            }
        }
        int m = INT_MAX;
        for (int i = 0; i < 26; i++) 
        {
            m = min(m, count[i][1]);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i][0] < m) 
            {
                ans++;
            }
        }
        return ans;
    }
};