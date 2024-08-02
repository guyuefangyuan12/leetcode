#include<vector>
#include<numeric>
using namespace std;
//�������飺
// 1.ÿ�ν�����ĺͳ������鳤��n,���õ�������ŵ������У�Ȼ��n--,
// �ܺͼ�ȥ��ǰ�Ĵ���������ظ��������̡�
//2.������ͳ������鳤��n�����õ��������������ÿ��λ���ϣ�Ȼ���������m�������ǰm��������1��

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