class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> c_map;
        for(const auto& e:words)
        {
            c_map[e]++;
        }
        multimap<int,string,greater<int>> s_map;
        for(const auto& e:c_map)
        {
            s_map.insert(make_pair(e.second,e.first));
        }
        vector<string> result;
        auto it=s_map.begin();
        while(it!=s_map.end()&&k--!=0)
        {
            result.push_back(it->second);
            ++it;
        }
        return result;
    }
};