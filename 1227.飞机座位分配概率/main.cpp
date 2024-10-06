#include<vector>
using namespace std;
class Solution
{
public:
	double nthPersonGetsNthSeat(int n)
	{
		return n == 1 ? 1 / n : 1.0 / 2;
	}
};