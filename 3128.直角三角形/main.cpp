#include<vector>
using namespace std;

class Solution 
{
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m,0);
        vector<int> column(n, 0);
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == 1) 
                {
                    row[i]++;
                    column[j]++;
                }
            }
        }
        long long  ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans += (row[i] - 1) * (column[j] - 1);
                }
            }
        }
        return ans;
    }
};