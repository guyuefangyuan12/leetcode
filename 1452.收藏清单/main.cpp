#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies)
	{
		int n = favoriteCompanies.size();
		vector<int> flag(n);
		unordered_map<string, int> map;
		int cnt = 1;
		for (vector<string> company : favoriteCompanies)
		{
			for (string str : company) {
				map[str] = 1;
			}
			for (int i = 0; i < n; i++)
			{
				if (!flag[i])
				{
					if (favoriteCompanies[i].size() < map.size())
					{
						int j;
						for (j = 0; j < favoriteCompanies[i].size(); j++)
							if (!map.count(favoriteCompanies[i][j])) {
								break;
							}
						if (j == favoriteCompanies[i].size()) {
							flag[i] = 1;
						}
					}
				}
			}
			map.clear();
		}
		vector<int> count;
		for (int i = 0; i < n; i++)
		{
			if (flag[i] == 0)
			{
				count.push_back(i);
			}
		}
		return count;
	}
};

int main() {
	vector<vector<string>> i = { {"leetcode","google","facebook"},{"google","microsoft"},{"google","facebook"},{"google"},{"amazon"} };
	Solution s;
	s.peopleIndexes(i);
}