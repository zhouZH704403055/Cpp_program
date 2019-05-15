class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> tmp;
        for(int i=0;i<array.size();i++)
        {
            if((array[i]&1)==1)
            {
                tmp.push_back(array[i]);
            }
        }
        for(int i=0;i<array.size();i++)
        {
            if((array[i]&1)==0)
            {
                tmp.push_back(array[i]);
            }
        }
        array=tmp;
    }
};