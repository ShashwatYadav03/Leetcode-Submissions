class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int n = a.size();
        for(int i =0; i<n; i++){
            while(a[i] != a[a[i]-1]) swap(a[i],a[a[i]-1]);
        }
        vector<int> ans;
        for(int i=0;i<n; i++){
            if(a[i] != i+1) ans.push_back(a[i]);
        }
        return ans;
    }
};