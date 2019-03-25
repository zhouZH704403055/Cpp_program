class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num[m+n];
        int i = 0,j = 0,k = 0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j])
                num[k++] = nums1[i++];
            else
                num[k++] = nums2[j++];
        }
        while(i < m) num[k++] = nums1[i++];
        while(j < n) num[k++] = nums2[j++];
        copy(num,num+m+n,nums1.begin());
    }
};
