#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		vector<int> city(n);
		for (auto i : roads) {
			city[i[0]]++;
			city[i[1]]++;
		}
		int rank = 0;
		int k = max_element(city.begin(), city.end()) - city.begin();
		int Max = city[k];
		if (Max == 0) return 0;
		int secondMax;
		vector<int> secondmax;
		vector<int> max = { k };
		city[k] = 0;
		while (1) {
			int temp = max_element(city.begin(), city.end()) - city.begin();
			if (city[temp] == Max) {
				max.push_back(temp);
				city[temp] = 0;
			}
			else break;
		}
		if (max.size() == 1) {
			int n = max_element(city.begin(), city.end()) - city.begin();
			secondMax = city[n];
			secondmax.push_back(n);
			city[n] = 0;
			while (1) {
				int temp = max_element(city.begin(), city.end()) - city.begin();
				if (city[temp] == secondMax) {
					secondmax.push_back(temp);
					city[temp] = 0;
				}
				else break;
			}
		}
		if (max.size() == 1) {
			for (int i = 0; i < secondmax.size(); i++) {
				vector<int> temp1 = { k,secondmax[i] };
				vector<int> temp2 = { secondmax[i],k };
				if (find(roads.begin(), roads.end(), temp1) != roads.end() || find(roads.begin(), roads.end(), temp2) != roads.end()) {
					rank = Max + secondMax - 1;

				}
				else {
					rank = Max + secondMax;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < max.size(); i++) {
				int j = 0;
				for (j = i + 1; j < max.size(); j++) {
					vector<int> temp1 = { max[i],max[j] };
					vector<int> temp2 = { max[j],max[i] };
					if (find(roads.begin(), roads.end(), temp1) != roads.end() || find(roads.begin(), roads.end(), temp2) != roads.end()) {
						rank = Max + Max - 1;

					}
					else {
						rank = Max + Max;
						break;
					}
				}
				if (j != max.size())
					break;
			}
		}
		return rank;
	}
};


int main() {
	vector<vector<int>> roads = { {1,0} };
	Solution s;
	s.maximalNetworkRank(2, roads);
}
