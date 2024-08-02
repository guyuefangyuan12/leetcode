#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> xs, ys;
        for (auto& p : points) {
            xs.insert(p[0] + p[1]);
            ys.insert(p[1] - p[0]);
        }

        int ans = INT_MAX;
        for (auto& p : points) {
            int x = p[0] + p[1], y = p[1] - p[0];
            xs.erase(xs.find(x)); // �Ƴ�һ�� x
            ys.erase(ys.find(y)); // �Ƴ�һ�� y

            int dx = *xs.rbegin() - *xs.begin();
            int dy = *ys.rbegin() - *ys.begin();
            ans = min(ans, max(dx, dy));

            xs.insert(x);
            ys.insert(y);
        }
        return ans;
    }
};

