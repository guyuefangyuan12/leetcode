#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
	int count(int val1, int val2) {
		int cnt = 0;
		int n1 = log(val1) / log(2);
		int n2 = log(val2) / log(2);
		if (n1 > n2) {
			cnt = count1(val1 / pow(2, n1 - n2), val2);
			cnt += n1 - n2;
		}
		else if (n2 > n1) {
			cnt = count1(val1, val2 / pow(2, n2 - n1));
			cnt += n2 - n1;
		}
		else {
			cnt = count1(val1, val2);
		}
		return cnt;
	}

	int count1(int val1, int val2) {
		int n = 0;
		while (val1 != val2) {
			val1 = val1 >> 1;
			val2 = val2 >> 1;
			n=n+2;
		}
		return n;
	}

	vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
		int m = queries.size();
		vector<int> answer(m);
		for (int i = 0; i < m; i++) {
			answer[i] = count(queries[i][0], queries[i][1]);
			answer[i]++;
		}
		return answer;
	}
};
int main() {
	vector<vector<int>> queries = { {5,3},{4,7},{2,3} };
	Solution s;
	s.cycleLengthQueries(3, queries);
}