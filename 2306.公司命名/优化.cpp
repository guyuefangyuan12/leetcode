#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int size[26]{}; // 集合大小
        int intersection[26][26]{}; // 交集大小
        unordered_map<string, int> groups; // 后缀 -> 首字母
        for (auto& s : ideas) {
            int b = s[0] - 'a';
            size[b]++; // 增加集合大小
            auto suffix = s.substr(1);
            int mask = groups[suffix];
            groups[suffix] = mask | 1 << b; // 把 b 加到 mask 中
            for (int a = 0; a < 26; a++) { // a 是和 s 有着相同后缀的字符串的首字母
                if (mask >> a & 1) { // a 在 mask 中
                    intersection[b][a]++; // 增加交集大小
                    intersection[a][b]++;
                }
            }
        }

        long long ans = 0;
        for (int a = 1; a < 26; a++) { // 枚举所有组对
            for (int b = 0; b < a; b++) {
                int m = intersection[a][b];
                ans += (long long)(size[a] - m) * (size[b] - m);
            }
        }
        return ans * 2; // 乘 2 放到最后
    }
};