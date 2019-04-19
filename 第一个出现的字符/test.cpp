class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char,int> map;
        for(auto e:str)
        {
            map[e]++;
        }
        for(int i=0;i<str.size();i++)
        {
            if(map[str[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};