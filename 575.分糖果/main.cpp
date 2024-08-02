#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int distributeCandies(vector<int>& candyType) 
    {
        int n = candyType.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) 
        {
            if (map.count(candyType[i])) 
            {
                map[candyType[i]]++;
            }
            else 
            {
                map[candyType[i]] = 1;
            }
        }
        return max((int)map.size(), n / 2);
    }
};