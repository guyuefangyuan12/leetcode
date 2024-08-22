#include<string>
using namespace std;

class Solution 
{
public:
    bool checkRecord(string s) 
    {
        int A = 0;
        int L = 0;
        for (char ch : s) 
        {
            if (ch == 'A') 
            {
                A++;
                L = 0;
            }
            else if (ch == 'L') 
            {
                L++;
            }
            else 
            {
                L = 0;
            }
            if (A == 2 || L == 3)
            {
                return false;
            }
        }
        return true;
    }
};