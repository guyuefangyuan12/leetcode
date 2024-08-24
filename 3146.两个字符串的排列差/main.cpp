#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    int findPermutationDifference(string s, string t) 
    {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int>map;
        for (int i = 0; i < n; i++) 
        {
            map[s[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            ans += abs(i - map[t[i]]);
        }
        return ans;
    }
};
