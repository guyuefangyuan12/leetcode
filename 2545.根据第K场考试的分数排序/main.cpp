#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
		int m = score.size();
		int n = score[0].size();
		vector<int> temp(m);
		for (int i = 0; i < m; i++) {
			temp[i]=score[i][k];
		}
		sort(temp.rbegin(), temp.rend());
		
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				if (score[j][k] == temp[i])
					swap(score[i], score[j]);
			}
		}
		return score;
	}
};

int main() {
	vector<vector<int>> score = { {10,6,9,1} ,{7,5,11,2},{4,8,3,15} };
	Solution s;
	s.sortTheStudents(score, 2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout<<score[i][j];
		}
	}
}