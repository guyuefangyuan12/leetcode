#include<vector>
using namespace std;

class MyHashMap 
{
private:
    vector<int> Key;
    vector<int> Value;

public:
    MyHashMap() 
    {

    }

    void put(int key, int value) 
    {
        int pos = find(Key.begin(), Key.end(), key) - Key.begin();
        if (pos == Key.size())
        {
            Key.push_back(key);
            Value.push_back(value);
        }
        else
        {
            Value[pos] = value;
        }

    }

    int get(int key) 
    {
        int pos=find(Key.begin(), Key.end(), key)-Key.begin();
        if (pos == Key.size()) 
        {
            return -1;
        }
        else
            return Value[pos];
    }

    void remove(int key) 
    {
        int pos = find(Key.begin(), Key.end(), key) - Key.begin();
        if (pos != Key.size())
        {
            Key.erase(pos + Key.begin());
            Value.erase(pos + Value.begin());
        }
    }
};
