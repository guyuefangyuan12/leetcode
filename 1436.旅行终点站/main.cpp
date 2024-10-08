#include<vector>
#include<string>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution 
{
public:
    string destCity(vector<vector<string>>& paths)
    {
        unordered_map<string, string>map;
        int n = paths.size();
        for (int i = 0; i < n; i++) 
        {
            map[paths[i][0]] = paths[i][1];
        }
        function<string(string)>dfs = [&](string s)->string
            {
                if (map.count(s)) 
                {
                    return dfs(map[s]);
                }
                else 
                {
                    return s;
                }
            };
        return dfs(paths[0][0]);
    }
};