#include<vector>
#include<cmath>
using namespace std;

class Solution {
	int pow(long long x, long long n, long long mod) {
		long long res = 1 % mod;
		for (; n; n /= 2) {
			if (n % 2) {
				res = res * x % mod;
			}
			x = x * x % mod;
		}
		return res;
	}

	long long sum_e(long long k) {
		long long res = 0, n = 0, cnt1 = 0, sum_i = 0;
		for (long long i = log2(k + 1); i; i--) {
			long long c = (cnt1 << i) + (i << (i - 1)); // �������ݴθ���
			if (c <= k) {
				k -= c;
				res += (sum_i << i) + ((i * (i - 1) / 2) << (i - 1));
				sum_i += i; // ֮ǰ��� 1 ���ݴ�֮��
				cnt1++; // ֮ǰ��� 1 �ĸ���
				n |= 1LL << i; // �� 1
			}
		}
		// ���λ��������
		if (cnt1 <= k) {
			k -= cnt1;
			res += sum_i;
			n |= 1; // ���λ�� 1
		}
		// ʣ��� k ���ݴΣ��� n �ĵ� k �� 1 ����
		while (k--) {
			res += __builtin_ctzll(n);
			n &= n - 1; // ȥ�����λ�� 1����Ϊ 0��
		}
		return res;
	}

public:
	vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
		vector<int> ans;
		for (auto& q : queries) {
			auto er = sum_e(q[1] + 1);
			auto el = sum_e(q[0]);
			ans.push_back(pow(2, er - el, q[2]));
		}
		return ans;
	}
};