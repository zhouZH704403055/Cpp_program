class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max=array[0];
        int sum=0;
        for(auto e:array)
        {
            sum+=e;
            if(sum>max)
            {
                max=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return max;
    }
};