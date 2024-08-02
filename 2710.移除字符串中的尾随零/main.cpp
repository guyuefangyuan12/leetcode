#include<string>
using namespace std;
class Solution
{
public:
	string removeTrailingZeros(string num)
	{
		while (*(num.end() - 1) == '0') 
		{
			num.erase(num.end() - 1);
		}
		return num;
	}
};