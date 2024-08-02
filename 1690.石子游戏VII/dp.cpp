#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> s(n + 1);
        partial_sum(stones.begin(), stones.end(), s.begin() + 1);
        vector<int> f(n);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                f[j] = max(s[j + 1] - s[i + 1] - f[j], s[j] - s[i] - f[j - 1]);
            }
        }
        return f[n - 1];
    }
};

