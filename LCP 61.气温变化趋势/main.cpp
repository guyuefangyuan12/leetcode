#include<vector>
using namespace std;

class Solution
{
public:
	int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB)
	{
		int n = temperatureA.size();
		vector<int> diff1(n);
		vector<int> diff2(n);
		for (int i = 1; i < n; i++)
		{			
			if (temperatureA[i] - temperatureA[i - 1]>0)
			{
				diff1[i] = 1;
			}
			else if (temperatureA[i] - temperatureA[i - 1] == 0) 
			{
				diff1[i] = 0;
			}
			else 
			{
				diff1[i] = -1;
			}

			if (temperatureB[i] - temperatureB[i - 1] > 0)
			{
				diff2[i] = 1;
			}
			else if (temperatureB[i] - temperatureB[i - 1] == 0)
			{
				diff2[i] = 0;
			}
			else
			{
				diff2[i] = -1;
			}
		}
		int left = 1; 
		int right = 1;
		int Max = 0;
		while (right < n-1) 
		{
			if (diff1[left] == diff2[left])
			{
				right++;
				if (diff1[right] != diff2[right]) 
				{
					Max = max(Max, right - left);
					left = right + 1;				
				}				
			}
			else 
			{
				left++;
				right++;
			}			
		}
		if (diff1[right] == diff2[right])
		{
			Max = max(Max, right - left + 1);
		}
		return Max;
	}
};

int main() {
	vector<int> t1 = { -14,7,-19,9,13,40,19,15,-18 };
	vector<int> t2 = { 3,16,28,32,25,12,13,-6,4 };
	Solution s;
	s.temperatureTrend(t1, t2);
}