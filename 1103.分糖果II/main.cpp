#include<vector>
using namespace std;

class Solution
{
public:
	vector<int> distributeCandies(int candies, int num_people)
	{
		vector<int> ans(num_people);
		for (int i = 0; candies > 0; i++)
		{
			ans[i % num_people] += (candies > i + 1 ? i + 1 : candies);
			candies -= (candies > i + 1 ? i + 1 : candies);
		}
		return ans;
	}
};