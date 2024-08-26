#include<vector>
#include<functional>
using namespace std;

class Employee
{
public:
	int id;
	int importance;
	vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id)
	{
		int n = employees.size();
		vector<int> ids(2000, -1);
		for (int i = 0; i < n; i++)
		{
			ids[employees[i]->id - 1] = i;
		}
		function<int(int)>dfs = [&](int i)->int
			{
				int ans = 0;
				if (employees[ids[i - 1]]->subordinates.empty())
				{
					return employees[ids[i - 1]]->importance;
				}
				for (int j : employees[ids[i - 1]]->subordinates)
				{
					ans += dfs(j);
				}
				return ans + employees[ids[i - 1]]->importance;
			};
		return dfs(id);
	}
};