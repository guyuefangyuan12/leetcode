#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
public:
	int minimumOperationsToMakeKPeriodic(string word, int k)
	{
		int n = word.size();
		unordered_map<string, int> map;
		int ans = 0;
		for (int i = 0; i < n; i += k)
		{
			string temp;
			temp.insert(temp.begin(), word.begin() + i, word.begin() + i + k);
			if (map.count(temp))
			{
				map[temp]++;
				ans = max(ans, map[temp]);
			}
			else
			{
				map[temp] = 1;
				ans = max(ans, map[temp]);
			}
		}
		return n / k - ans;
	}
};

int main()
{
	string word = "xu";
	Solution s;
	s.minimumOperationsToMakeKPeriodic(word, 1);
}