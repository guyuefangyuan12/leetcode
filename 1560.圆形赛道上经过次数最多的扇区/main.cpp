#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int m = rounds.size();
        vector<int> count(n);
        vector<int> re;
        count[rounds[0]-1]++;
        for (int i = 1; i < m; i++) {
            int first = rounds[i - 1];
            int end = rounds[i];
            while (first != end) {
                first++;
                if (first > n) {
                    first = 1;
                }
                count[first-1]++;
           }
        }
        int Max = *max_element(count.begin(), count.end());
        for (int i = 0; i < n; i++) {
            if (count[i] == Max) {
                re.push_back( i + 1);
            }
        }
        return re;
    }
};

int main() {
    vector<int> rounds = { 2,1,2,1,2,1,2,1,2 };
    Solution s;
    s.mostVisited(2, rounds);
}