class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i =0; // i will travel on zeros
        int j =0; // j will travel on non-zeros
        while(i<n && j<n){
            if(nums[i]==0 && nums[j]!=0){
                if(j>i) swap(nums[i],nums[j]);
                else j++;
            }
            if(nums[i]!=0)i++;
            if(nums[j]==0)j++;
        }
    }
};