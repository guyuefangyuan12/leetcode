#include<vector>
#include<unordered_set>
#include<algorithm>
#include<stack>
using namespace std;
//����̰��
/*��������Ӵ�С�����Ȱ�ǰ k ����Ŀѡ�ϡ�

���ǵ� k + 1����Ŀ�����Ҫѡ�������Ǳ����ǰ k ����Ŀ���Ƴ�һ����Ŀ��
�����Ѿ���������Ӵ�С����ѡ�����Ŀ������ totalProfit ��������ص㿼���ܷ��� distinctCategories ���
�������ۣ�

����� k + 1k + 1k + 1 ����Ŀ��ǰ��ĳ����ѡ��Ŀ�������ͬ����ô������ô�Ƴ��������� distinctCategories �����������ѡ�������Ŀ��
����� k + 1k + 1k + 1 ����Ŀ��ǰ���κ���ѡ��Ŀ����𶼲�һ���������Ƴ�ǰ����ѡ��Ŀ�е���һ����
����Ƴ�����Ŀ�����ֻ����һ�Σ���ôѡ�� k + 1 ����Ŀ��distinctCategories һ��һ�������ֲ��䣬���Բ��������������
����Ƴ�����Ŀ������ظ����ֶ�Σ���ôѡ�� k + 1 ����Ŀ��distinctCategories ������һ����ʱ�п��ܻ������Ŷȱ��һ��Ҫѡ�������Ŀ��Ϊʲô˵��һ�����أ���Ϊ totalProfit\textit{ totalProfit }totalProfit ֻ���С���������ڵ�Ŀ������� totalProfit\textit{ totalProfit }totalProfit ���־�����ͬʱ�� distinctCategories\textit{ distinctCategories }distinctCategories ���ӣ���ô���� distinctCategories\textit{ distinctCategories }distinctCategories ���Ӿ�����ѡ�ϣ���Ϊ����������С�����ڲ�ѡ�Ļ����� totalProfit\textit{ totalProfit }totalProfit ֻ���С��
����������̣���������ѡ��������Ŀ���������Ŷȣ�ȡ���ֵ����Ϊ�𰸡�

����ʵ��ʱ������Ӧ���Ƴ���ѡ��Ŀ������ǰ���ظ���������С����Ŀ���������һ��ջ duplicate��ά������������Ӵ�С��������ջ��������С��������ջǰ�ж� category\textit{ category }category ֮ǰ�Ƿ���������û��������ջ��
*/

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        // ������Ӵ�С����
        sort(items.begin(), items.end(), [](const auto& a, const auto& b) { return a[0] > b[0]; });
        long long ans = 0, total_profit = 0;
        unordered_set<int> vis;
        stack<int> duplicate; // �ظ���������
        for (int i = 0; i < items.size(); i++) {
            int profit = items[i][0], category = items[i][1];
            if (i < k) {
                total_profit += profit; // �ۼ�ǰ k ����Ŀ������
                if (!vis.insert(category).second) { // �ظ����
                    duplicate.push(profit);
                }
            }
            else if (!duplicate.empty() && vis.insert(category).second) { // ֮ǰû�е����
                total_profit += profit - duplicate.top(); // ѡһ���ظ�����е���С�����滻
                duplicate.pop();
            } // else����ǰ�������С����������ظ��ˣ�ѡ��ֻ���� total_profit ��С��vis.size() ���䣬���ŶȲ�����
            ans = max(ans, total_profit + (long long)vis.size() * (long long)vis.size());
        }
        return ans;
    }
};

