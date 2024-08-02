#include<string>
#include<vector>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Solution
{
public:

	template <typename T>
	std::string to_string_with_precision(const T a_value, const int n = 6)
	{
		int nn = n;
		std::ostringstream out;
		out << std::fixed << std::setprecision(nn) << a_value;
		return out.str();
	}
	string discountPrices(string sentence, int discount)
	{
		int flag1 = 1;
		int flag2 = 0;
		string temp;
		vector<string>price;
		vector<int>pos;
		int pos_temp;
		int n = sentence.size();
		for (int i = 0; i < n; i++)
		{
			if (flag1 == 0)
			{
				if (sentence[i] == ' ')
				{
					flag1 = 1;
				}
			}
			else
			{
				if (flag2 == 0) {
					if (sentence[i] == '$')
					{
						flag2 = 1;
						pos_temp = i;
					}
					else
					{
						flag1 = 0;
					}
				}
				else
				{
					if (sentence[i] >= '0' && sentence[i] <= '9')
					{
						temp.push_back(sentence[i]);
					}
					else if (sentence[i] == ' ')
					{
						if (temp.size())
						{
							price.push_back(temp);
							pos.push_back(pos_temp);
						}
						temp.clear();
						flag2 = 0;
					}
					else
					{
						flag2 = 0;
						flag1 = 0;
						temp.clear();
					}
				}
			}
		}
		if (temp.size()) 
		{
			price.push_back(temp);
			pos.push_back(pos_temp);
		}
		int sum = 0;
		for (int i = 0; i < pos.size(); i++)
		{
			double t1=stod(price[i]);
			sentence.erase(sum+ pos[i] + 1, price[i].size());
			int l = price[i].size();
			double t2 = t1  * (100-discount )/100;
			price[i] = to_string_with_precision(t2, 2);
			sentence.insert(sum + pos[i] + 1, price[i]);
			sum = sum + price[i].size() - l;
		}
		return sentence;
	}
};

int main() {
	string se = "favsijl39l3ur$czt6rz hz $68050 lz9 ny 59o $4 $ $";
	Solution s;
	s.discountPrices(se, 84);
}