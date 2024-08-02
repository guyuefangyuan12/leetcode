#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution
{
public:
	bool issubstr(string& str1, string& str2)
	{
		int pos = -1;
		for (char& c : str2)
		{
			pos = str1.find(c, pos + 1);
			if (pos == str1.npos)
			{
				return false;
			}
		}
		return true;
	}
	int findLUSlength(vector<string>& strs)
	{
		unordered_map<string, int>map;
		int n = strs.size();
		for (string& s : strs) 
		{
			if (map.count(s)) 
			{
				map[s]++;
				
			}
			else 
			{
				map[s]=1;
			}
		}
		vector<vector<string>>s(11);
		vector<string> count;
		for (auto& i : map) 
		{
			s[i.first.size()].push_back(i.first);
			if (i.second == 1) 
			{
				count.push_back(i.first);
			}
		}
		int Max = -1;
		for (string& str2 : count) 
		{
			int flag = 0;
			for (int i = str2.size() + 1; i < 10; i++) 
			{
				for (string& str1 : s[i]) 
				{
					if (issubstr(str1, str2)) 
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1) 
				{
					break;
				}
			}
			if (flag == 0) 
			{
				Max = max(Max, int(str2.size()));
			}
		}
		return Max;
	}
};

int main() {
	vector<string> strs = { "chksawwkqz","bzwbdfakgy","wagicijtzj","cjyvjfybza","froxvupwek","jqylphqgnu","gqciswckdo","gfgfugmaet","oweeowrtid","ajfptjdvtu","qnnglbfxzz","zenfmxxuob","gtpktogaxt","fenjvirifm","hrrwufnjwu","fuibpucisl","evrecdqhdb","jompupwwhp","ceohrtlyhm","rwsuzsduuv","gphzgqkwrj","hwsacfgxwe","cetzwavsxt","rocjffycpi","dzwtltsdtl","kmssffvlfw","eygcnjqoqc","tbqnhrfaam","hsylfiwwhm","ummdydcubq","snivlwozoz","uepguepssc","noqnyezngp","rmhxhqptgn","iovcscjeuz","gnrnbqsnav","ccjqgntxlh","ftpixpzdul","ptombomeyo","muvqikarar","hlruinhfqa","hokjhojdpt","antaicotqw","pucqdmdoya","wjmcsvkebs","atcvczvdin","rtfpzlmfpe","vrhmwagerr","ajgpajjpxf","dupzhbmkqw" };
	Solution s;
	s.findLUSlength(strs);
}