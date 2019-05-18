class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        std::sort(input.begin(),input.end());
        vector<int> tmp;
        if(k>input.size())
        {
            return tmp;
        }
        for(int i=0;i<k;i++)
        {
            tmp.push_back(input[i]);
        }
        return tmp;
    }
};