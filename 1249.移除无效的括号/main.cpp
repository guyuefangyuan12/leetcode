#include<string>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class Solution 
{
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<char> str;
        stack<int> left;
        vector<int> right;
        int n = s.size();
        for (int i = 0; i < n; i++) 
        {
            if (s[i] == '(') 
            {
                left.push(i);
            }
            else if (s[i] == ')') 
            {
                if (left.empty()) 
                {
                    right.push_back(i);
                }
                else 
                {
                    left.pop();
                }
            }
        }
        while (!left.empty()) 
        {
            right.push_back(left.top());
            left.pop();
        }
        sort(right.begin(), right.end());
        for (int i = right.size() - 1; i >= 0; i--) 
        {
            s.erase(right[i],1);
        }
        return s;
    }
};

int main() {
    string str = "a)b(c)d";
    Solution s;
    s.minRemoveToMakeValid(str);
}