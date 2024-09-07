#include<vector>
using namespace std;
class Solution
{
public:
	int accountBalanceAfterPurchase(int purchaseAmount)
	{
		return (purchaseAmount % 10 < 5 ? 100 : 90) - purchaseAmount + purchaseAmount % 10;
	}
};