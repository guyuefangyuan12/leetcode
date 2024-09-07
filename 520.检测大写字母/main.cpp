#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
	bool detectCapitalUse(string word)
	{
		//string upper;
		//string lower;
		int cnt = 0;
		int n = word.size();
		for (int i = 0; i < n; i++)
		{
			if (isupper(word[i]))
			{
				//upper.push_back(word[i]);
				cnt++;
			}
			else
			{
				//lower.push_back(word[i]);
			}
		}
		/*
		if ((isupper(word[0]) && (upper.empty() || lower.empty())) || (!isupper(word[0])) && upper.empty())
		{
			return true;
		}
		*/
		if (cnt == n || (cnt == 1 && isupper(word[0])) || cnt == 0)
		{
			return true;
		}
		return false;
	}
};