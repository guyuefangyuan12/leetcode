#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>>& paths) 
    {
        set<string>s;
        int n = paths.size();
        for (int i = 0; i < n; i++)
        {
            s.insert(paths[i][0]);
        }
        for (int i = 0; i < n; i++) 
        {
            if (!s.count(paths[i][1]))
            {
                return paths[i][1];
            }
        }
        return "A";
    }
};