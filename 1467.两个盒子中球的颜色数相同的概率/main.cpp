#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int left[10]; //ʣ���������������ڼ�֦
    double powerof2[15] = { 1, 2, 4, 8, 16,32, 64, 128, 256,512,1024,2048,4096,8192,16384 }; //2���ݣ�����������������
    int n = 0;
    long long factorial[15];//��׳ˣ����ڼ��������
    double getProbability(vector<int>& balls) {
        calculatefactorial();
        n = balls.size();
        int sum = 0; //һ���ж��ٸ����������ĳ���
        for (int i = 0; i < n; i++)
            sum += balls[i];
        double q = 1; //�����C(2n, n)/2^(2n)����������n��n�ĸ���
        for (int i = 1; i <= sum / 2; i++) {
            q *= (i + sum / 2) * 1.0 / i / 4;
        }
        left[n - 1] = balls[n - 1]; //����ʣ�����������ڼ�֦
        for (int i = n - 2; i >= 0; i--)
            left[i] = left[i + 1] + balls[i];
        return dfs(balls, 0, 0, 0) / q;
    }
    //����׳ˣ�������
    void calculatefactorial() {
        factorial[0] = 1;
        for (int i = 1; i <= 10; i++)
            factorial[i] = i * factorial[i - 1];
    }
    //���ݹ�ʽ�������
    int combination(int a, int b) {
        return factorial[a] / (factorial[b] * factorial[a - b]);
    }
    //���Ѻ�����balls����Ŀ�������飬m����ǰ������ɫm��greatersum����ߵ����ӱ��ұ����Ӷ༸����greatercolor����߱��ұ߶༸����ɫ
    double dfs(vector<int>& balls, int m, int greatersum, int greatercolor) {
        if (m == n) //ֻ������ұ������������ɫ������������ʱ���㣬������̸
            return greatersum == 0 && greatercolor == 0;
        //��֦������Ŀǰ��ʣ��x����û�з��䣬������߱��ұߵ����������������ұ����ӱ�������Ӷ���������������x����ô����������ô���䣬�������������������������������������������Լ�֦
        if (abs(greatersum) > left[m])
            return 0;
        double result = 0;
        //����ȡ��ͬ�������������ߣ�������������ĸ��� ����л���� @��ľ�� �ĸĽ���
        for (int i = 0; i <= balls[m]; i++) {
            int color = i == 0 ? -1 : (i == balls[m] ? 1 : 0);
            result += (combination(balls[m], i) / powerof2[balls[m]]) *
                dfs(balls, m + 1, greatersum + i - (balls[m] - i), greatercolor + color);
        }
        /* ԭ����д����Ҫд���Σ�̫�������
        for(int i = 0; i <= balls[m];i ++){
            if(i == 0){
                result +=  dfs(balls, m+1, greatersum-balls[m], greatercolor-1)/powerof2[balls[m]];
            }
            else if(i == balls[m]){
                result +=  dfs(balls, m+1, greatersum+balls[m], greatercolor+1)/powerof2[balls[m]];
            }
            else{
                result += (combination(balls[m], i)/powerof2[balls[m]]) * dfs(balls, m+1, greatersum + (i-(balls[m]-i)), greatercolor);
            }
        }
        */
        return result;
    }

};