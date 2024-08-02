#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
	string baseNeg2(int n)
	{
		int flag1 = 0;
		bool flag2 = false;
		string s;
		while (n)
		{
			s.insert(0, to_string((n % 2 + flag1) % 2));
			if(!flag2)
			{
				flag1 = (n % 2 + flag1) / 2;
			}
			if (flag2 && n % 2)
			{
				flag1 =1;
			}
			flag2 = !flag2;
			n /= 2;
		}
		if (flag1) 
		{
			s.insert(0, to_string(1));
		}
		if (s.empty()) 
		{
			s.insert(0, to_string(0));
		}
		if (s.size() % 2 == 0) 
		{
			s.insert(0, to_string(1));
		}
		return s;
	}
};

int main()
{
	Solution s;
	s.baseNeg2(14);
}