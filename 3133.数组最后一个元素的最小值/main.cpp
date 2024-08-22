#include<vector>
using namespace std;

class Solution
{
public:
	long long minEnd(int n, int x)
	{
		vector<int> num1;
		long long ans = 0;
		n = n - 1;
		int m = num1.size();
		int pos = 0;
		while (n | x)
		{
			long long temp = n & 1;
			if (x == 0)
			{
				ans = ans | temp << pos;
				n = n >> 1;
			}
			else
			{
				if ((x & 1) == 1)
				{
					ans = ans | 1 << pos;
				}
				else
				{
					ans = ans | temp << pos;
					n = n >> 1;
				}
				x = x >> 1;
			}
			pos++;
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.minEnd(3,4);
}