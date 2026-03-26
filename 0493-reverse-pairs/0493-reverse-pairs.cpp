class Solution {
public:
    int ans =0;
    void merge(vector<int>&nums, int lo, int mid, int hi){
        int i = lo, j=mid+1;
        while(i<= mid && j<= hi){
            if((long long int)nums[i]>(long long int)2*nums[j]){
                ans += mid-i +1;
                j++;
            }
            else i++;
        }
        i = lo, j=mid+1;
        vector<int>b;
        while(i<= mid && j<= hi){
            if(nums[i]<nums[j]) b.push_back(nums[i++]);
            else b.push_back(nums[j++]);
        }
        while(i<=mid)b.push_back(nums[i++]);
        while(j<=hi)b.push_back(nums[j++]);
        for(int i =lo; i<=hi; i++)nums[i]=b[i-lo];
    }
    void mergesort(vector<int>& nums, int lo, int hi){
        if(lo==hi) return;
        int mid = (lo+hi)/2;
        mergesort(nums,lo,mid);
        mergesort(nums,mid+1,hi);
        merge(nums,lo,mid,hi);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return ans;
    }
};