class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
        {
            return false;
        }
        for(int t=0;t<array.size();t++)
        {
            if(array[0].empty())
            {
                return false;
            }
        }
        int i=0;
        int j=array[0].size()-1;
        while(array[i][j]!=target)
        {
            if(target>array[i][j])
            {
                i++;
            }
            else if(target<array[i][j])
            {
                j--;
            }
            if(i<0||i>=array.size()||j<0||j>=array[0].size())
            {
                return false;
            }
        }
        return true;
    }
};