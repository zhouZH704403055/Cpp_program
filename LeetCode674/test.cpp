class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        vector<int> v(nums.size(),0);
        v[0]=1;
        int Max=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                v[i]=v[i-1]+1;
                if(Max<v[i])
                {
                    Max=v[i];
                }
            }
            else
            {
                v[i]=1;
            }
        }
        return Max;
    }
};