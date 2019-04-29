class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.size()==0)
        {
            return result;
        }
        int start=0;
        int end=array.size()-1;
        int ret=array[start]+array[end];
        while(start<end)
        {
            ret=array[start]+array[end];
            if(ret==sum)
            {
                result.push_back(array[start]);
                result.push_back(array[end]);
                return result;
            }
            else if(ret>sum)
            {
                end--;
            }
            else{
                start++;
            }
        }
        return result;
    }
};