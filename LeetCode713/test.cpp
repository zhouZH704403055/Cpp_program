class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if (k <= 1)  return 0;
        int ret = 0;
        int sum = 1;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (j < nums.size() && sum * nums[j] < k)
            {
                sum *= nums[j];
                j++;
            }
            ret += (j - i);
            if (i == j) 
            {
                sum = 1;
                j++;
            }
            else
                sum /= nums[i];
        }
        return ret;
    }
};