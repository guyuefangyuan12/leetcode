#include<algorithm>

class Solution
{
public:
	int maxHeightOfTriangle(int red, int blue)
	{
		int ans = 0;
		int temp_r = red;
		int temp_b = blue;
		int cnt = 1;
		while (1)
		{
			if (temp_r < cnt)
			{
				break;
			}
			temp_r -= cnt;
			cnt++;
			if (temp_b < cnt)
			{
				break;
			}
			temp_b -= cnt;
			cnt++;
		}
		ans = cnt - 1;
		cnt = 1;
		temp_r = blue;
		temp_b = red;
		while (1)
		{
			if (temp_r < cnt)
			{
				break;
			}
			temp_r -= cnt;
			cnt++;
			if (temp_b < cnt)
			{
				break;
			}
			temp_b -= cnt;
			cnt++;
		}
		return std::max(ans, cnt - 1);
	}
};