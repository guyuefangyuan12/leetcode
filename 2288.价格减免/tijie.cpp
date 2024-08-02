#include<string>
#include<vector>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
//ͨ������������ȡÿ�����ʣ�Ч�ʱ�һ��һ���ַ��жϼ򵥣���Ч
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        double d = 1 - discount / 100.0;
        stringstream ss(sentence);
        string ans, w;
        while (ss >> w) { // һ�߷ָһ�߼ӵ�����
            if (!ans.empty()) {
                ans += ' ';
            }
            if (w.length() > 1 && w[0] == '$' && all_of(w.begin() + 1, w.end(), ::isdigit)) {
                stringstream s;
                s << fixed << setprecision(2) << '$' << stoll(w.substr(1)) * d;
                ans += s.str();
            }
            else {
                ans += w;
            }
        }
        return ans;
    }
};
