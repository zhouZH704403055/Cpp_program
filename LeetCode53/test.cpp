class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int sum=0;
        int _max=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(_max<sum)
            {
                _max=sum;
            }
            if(sum<=0)
            {
                sum=0;
            }
        }
        return _max;
    }
};