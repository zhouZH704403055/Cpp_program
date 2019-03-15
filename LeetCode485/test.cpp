class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int max_cnt = 0;
        
        /*---貌似--不支持auto关键字-----*/
        //for(auto &c : nums){
        //for(auto beg = nums.begin(),end = nums.end();beg != end;++beg){
        //int c = *beg;
        
        int size = nums.size();//只调用一次size()
        
        for(int i = 0; i<size;++i)
            if(nums[i] == 1) {
                ++cnt;
            }
            else{
                max_cnt = max(max_cnt,cnt);
                cnt = 0;
        }
        return max(max_cnt,cnt);//针对测试用例[1],没有机会进入else分支执行max()比较
    }
};