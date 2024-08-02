#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size()-1;
        int cnt = 0;
        while (right >= left) 
        {
            if (people[right] + people[left] <= limit) 
            {
                cnt++;
                left++;
                right--;
            }
            else 
            {
                right--;
                cnt++;
            }
        }
        return cnt;
    }
};
