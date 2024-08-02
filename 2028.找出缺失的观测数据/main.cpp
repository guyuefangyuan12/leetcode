#include<vector>
#include<numeric>
using namespace std;
//构造数组：
// 1.每次将数组的和除以数组长度n,将得到的数存放到数组中，然后n--,
// 总和减去当前的存入的数，重复上述过程。
//2.将数组和除以数组长度n，将得到的数存入数组的每个位置上，然后根据余数m给数组的前m个数加上1，

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        vector<int> nums;
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        sum = mean * (m + n) - sum;
        while (sum >= n && sum <= 6 * n) 
        {
            int temp = sum / n;
            sum -= temp;
            n--;
            nums.push_back(temp);
            if (n == 0) 
            {
                break;
            }
        }
        return nums;
    }
};