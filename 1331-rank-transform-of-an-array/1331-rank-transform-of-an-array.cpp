class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        vector<int> ans;
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int> mp;
        int r=1;

        for(auto x: sorted){
            if(mp.find(x)==mp.end()){
                mp[x]=r;
                r++;
            }
        }
        for(auto x: arr){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};