#include<algorithm>
using namespace std;
class Solution {
public:
    int minimizeSet(int d1, int d2, int n, int m) {
        int l = n + m, r = INT_MAX;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid, d1, d2, n, m)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool check(int v, int d1, int d2, int n, int m) {
        long c1 = v / d1;
        long c2 = v / d2;
        long cc = v / lcm(d1, d2);
        c1 -= cc;
        c2 -= cc;
        v -= cc;
        if (c1 > m) {
            v -= (c1 - m);
        }
        if (c2 > n) {
            v -= (c2 - n);
        }
        return v >= (n + m);
    }

    int gcd(int a, int b) {
        return b != 0 ? gcd(b, a % b) : a;
    }

    long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
};
