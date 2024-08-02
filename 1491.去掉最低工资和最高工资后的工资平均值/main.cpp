#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) 
    {
        int n = salary.size();
        int Max = *max_element(salary.begin(), salary.end());
        int Min = *min_element(salary.begin(), salary.end());
        int sum = accumulate(salary.begin(), salary.end(), 0);
        sum = sum - Max - Min;
        double average = sum * 1.0 / (n - 2);
        return average;
    }
};