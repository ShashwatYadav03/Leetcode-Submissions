class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        vector<int> ans;
        unordered_set<int>st;
        for(auto x: nums){
            mx = max(mx,x);
            mn = min(mn,x);
            st.insert(x);
        }
        for(int i = mn+1; i<mx; i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};