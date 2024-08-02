class Solution 
{
public:
    int distributeCandies(int n, int limit) 
    {
        int cnt = 0;
        for (int i = limit; i >= 0; i--) 
        {
            for (int j = limit; j >= 0; j--) 
            {
                for (int k = limit; k >= 0; k--) 
                {
                    if (i + j + k == n) 
                    {
                        cnt++;
                    }
                }
            }

        }
        return cnt;
    }
};