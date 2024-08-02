#include<vector>
#include<unordered_set>
#include<algorithm>
#include<stack>
using namespace std;
//反悔贪心
/*按照利润从大到小排序。先把前 k 个项目选上。

考虑第 k + 1个项目，如果要选它，我们必须从前 k 个项目中移除一个项目。
由于已经按照利润从大到小排序，选这个项目不会让 totalProfit 变大，所以重点考虑能否让 distinctCategories 变大。
分类讨论：

如果第 k + 1k + 1k + 1 个项目和前面某个已选项目的类别相同，那么无论怎么移除都不会让 distinctCategories 变大，所以无需选择这个项目。
如果第 k + 1k + 1k + 1 个项目和前面任何已选项目的类别都不一样，考虑移除前面已选项目中的哪一个：
如果移除的项目的类别只出现一次，那么选第 k + 1 个项目后，distinctCategories 一减一增，保持不变，所以不考虑这种情况。
如果移除的项目的类别重复出现多次，那么选第 k + 1 个项目后，distinctCategories 会增加一，此时有可能会让优雅度变大，一定要选择这个项目。为什么说「一定」呢？因为 totalProfit\textit{ totalProfit }totalProfit 只会变小，我们现在的目标就是让 totalProfit\textit{ totalProfit }totalProfit 保持尽量大，同时让 distinctCategories\textit{ distinctCategories }distinctCategories 增加，那么能让 distinctCategories\textit{ distinctCategories }distinctCategories 增加就立刻选上！因为后面的利润更小，现在不选的话将来 totalProfit\textit{ totalProfit }totalProfit 只会更小。
按照这个过程，继续考虑选择后面的项目。计算优雅度，取最大值，即为答案。

代码实现时，我们应当移除已选项目中类别和前面重复且利润最小的项目，这可以用一个栈 duplicate来维护，由于利润从大到小排序，所以栈顶就是最小的利润。入栈前判断 category\textit{ category }category 之前是否遇到过，没遇到才入栈。
*/

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        // 把利润从大到小排序
        sort(items.begin(), items.end(), [](const auto& a, const auto& b) { return a[0] > b[0]; });
        long long ans = 0, total_profit = 0;
        unordered_set<int> vis;
        stack<int> duplicate; // 重复类别的利润
        for (int i = 0; i < items.size(); i++) {
            int profit = items[i][0], category = items[i][1];
            if (i < k) {
                total_profit += profit; // 累加前 k 个项目的利润
                if (!vis.insert(category).second) { // 重复类别
                    duplicate.push(profit);
                }
            }
            else if (!duplicate.empty() && vis.insert(category).second) { // 之前没有的类别
                total_profit += profit - duplicate.top(); // 选一个重复类别中的最小利润替换
                duplicate.pop();
            } // else：比前面的利润小，而且类别还重复了，选它只会让 total_profit 变小，vis.size() 不变，优雅度不会变大
            ans = max(ans, total_profit + (long long)vis.size() * (long long)vis.size());
        }
        return ans;
    }
};

