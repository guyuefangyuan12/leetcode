#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class MagicDictionary
{
private:
	vector<string> s;
	unordered_map<int, vector<string>>map;
public:
	MagicDictionary()
	{
	}

	void buildDict(vector<string> dictionary)
	{
		for (string str : dictionary)
		{
			s.push_back(str);
			map[str.size()].push_back(str);
		}
	}

	bool search(string searchWord)
	{
		if (map.count(searchWord.size()))
		{
			for (string str : map[searchWord.size()])
			{
				int cnt = 0;
				for (int i = 0; i < searchWord.size() && cnt < 2; i++)
				{
					if (str[i] != searchWord[i])
					{
						cnt++;
					}
				}
				if (cnt == 1) 
				{
					return true;
				}
			}
			return false;
		}
		else
		{
			return false;
		}
	}
};