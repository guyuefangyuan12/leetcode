#include<string>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

class Solution
{
public:
	int maxConsecutiveAnswers(string answerKey, int k)
	{
		int n = answerKey.size();
		int left = 0;
		int right = 0;
		int ans = 0;
		char ch = 'T';
		int cnt = 0;
		while (right < n)
		{
			if (ch == answerKey[right])
			{
				right++;
			}
			else
			{
				if (cnt <= k)
				{
					cnt++;
					right++;
				}
				else
				{
					ans = max(ans, right - left);
					if (answerKey[left] != ch)
					{
						cnt--;
					}
					left++;
				}
			}
		}
		ans = max(ans, right - left);

		left = 0;
		right = 0;
		ch = 'F';
		cnt = 0;
		while (right < n)
		{
			if (ch == answerKey[right])
			{
				right++;
			}
			else
			{
				if (cnt <= k)
				{
					cnt++;
					right++;
				}
				else
				{
					ans = max(ans, right - left);
					if (answerKey[left] != ch)
					{
						cnt--;
					}
					left++;
				}
			}
		}
		ans = max(ans, right - left);
		return ans;
	}
};

int main() {
	string s = "TFFT";
	Solution ss;
	ss.maxConsecutiveAnswers(s, 1);
}