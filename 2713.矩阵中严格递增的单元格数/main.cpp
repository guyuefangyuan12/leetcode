#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                g[mat[i][j]].emplace_back(i, j); // ��ͬԪ�ط���ͬһ�飬ͳ��λ��
            }
        }

        vector<int> row_max(m), col_max(n);
        for (auto& [_, pos] : g) {
            // �Ȱ����� f ֵ����������ٸ��� row_max �� col_max
            vector<int> fs;
            for (auto& [i, j] : pos) {
                fs.push_back(max(row_max[i], col_max[j]) + 1);
            }
            for (int k = 0; k < pos.size(); k++) {
                auto& [i, j] = pos[k];
                row_max[i] = max(row_max[i], fs[k]); // ���µ� i �е���� f ֵ
                col_max[j] = max(col_max[j], fs[k]); // ���µ� j �е���� f ֵ
            }
        }
        return ranges::max(row_max);
    }
};

