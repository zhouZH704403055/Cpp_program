class Solution {
public:
int singleNumber(vector<int>& nums) {
int value = 0;
for(size_t i =0 ; i < nums.size(); ++i){
value ^= nums[i];
}
return value;
}
};