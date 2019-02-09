class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
// 将数组中的元素先放入优先级队列中
priority_queue<int> p(nums.begin(), nums.end());
// 将优先级队列中前k-1个元素删除掉
for(int i= 0; i < k-1; ++i)
{
p.pop();
}
return p.top();
}
};