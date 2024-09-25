#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int size[26]{}; // ���ϴ�С
        int intersection[26][26]{}; // ������С
        unordered_map<string, int> groups; // ��׺ -> ����ĸ
        for (auto& s : ideas) {
            int b = s[0] - 'a';
            size[b]++; // ���Ӽ��ϴ�С
            auto suffix = s.substr(1);
            int mask = groups[suffix];
            groups[suffix] = mask | 1 << b; // �� b �ӵ� mask ��
            for (int a = 0; a < 26; a++) { // a �Ǻ� s ������ͬ��׺���ַ���������ĸ
                if (mask >> a & 1) { // a �� mask ��
                    intersection[b][a]++; // ���ӽ�����С
                    intersection[a][b]++;
                }
            }
        }

        long long ans = 0;
        for (int a = 1; a < 26; a++) { // ö���������
            for (int b = 0; b < a; b++) {
                int m = intersection[a][b];
                ans += (long long)(size[a] - m) * (size[b] - m);
            }
        }
        return ans * 2; // �� 2 �ŵ����
    }
};