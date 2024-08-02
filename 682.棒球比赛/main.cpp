#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution
{
public:
	int calPoints(vector<string>& operations)
	{
		int ans = 0;
		int b1 = 0;
		int b2 = 0;
		int b3 = 0;
		vector<int> num;
		int n = operations.size();
		for (int i = 0; i < n; i++)
		{
			if (operations[i] == "C")
			{
				ans -= num.back();
				num.pop_back();
			}
			else if (operations[i] == "D")
			{
				ans += num.back() * 2;
				num.push_back(num.back() * 2);
			}
			else if (operations[i] == "+")
			{
				num.push_back(num.back() + num[num.size() - 2]);
				ans += num.back();
			}
			else 
			{
				num.push_back(stoi(operations[i]));
				ans += num.back();
			}
		}
		return ans;
	}
};