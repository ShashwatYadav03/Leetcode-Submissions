class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int p = nums[0];
        vector<int> pre(n);
        pre[0] = 1;
        for(int i =1; i<n; i++){
            pre[i]=p;
            p *= nums[i];
        }
        p = nums[n-1];
        for(int i = n-2; i>=0; i--){
            pre[i] *= p;
            p *= nums[i];
        }
        return pre;
    }
};