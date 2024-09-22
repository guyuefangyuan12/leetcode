#include<vector>
using namespace std;

class Solution
{
public:
	int findJudge(int n, vector<vector<int>>& trust)
	{
		vector<int>cnt(n, 0);
		vector<bool>t(n, false);
		for (vector<int> p : trust)
		{
			cnt[p[1]]++;
			t[p[0]] = true;
		}
		for (int i = 0; i < n; i++) 
		{
			if (!t[i] && cnt[i] == n - 1)
			{
				return i;
			}
		}
		return -1;
	}
};

int main() {
	vector<vector<int>> n = { {1,2} };
	Solution s;
	s.findJudge(2, n);
}