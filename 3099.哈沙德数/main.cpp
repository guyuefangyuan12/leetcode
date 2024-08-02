#include<vector>
using namespace std;

class Solution
{
public:
	int sumOfTheDigitsOfHarshadNumber(int x)
	{
		int sum = 0;
		int copy = x;
		while (x)
		{
			sum += x % 10;
			x /= 10;
		}
		return copy % sum ? -1 : sum;
	}
};

int main()
{
	int x = 23;
	Solution s;
	s.sumOfTheDigitsOfHarshadNumber(x);
}