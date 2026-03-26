class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n,vector<int>(n));
        int i=0;
        int k = 1;
        while(k<=n*n){
            int j = i;
            while(j<n-i){
                a[i][j++] = k++;
            }
            j=i+1;
            while(j<n-i){
                a[j++][n-i-1]=k++;
            }
            j=n-i-2;
            while(j>i){
                a[n-i-1][j--]=k++;
            }
            j=n-i-1;
            while(j>i){
                a[j--][i]=k++;
            }
            i++;
        }
        return a;
    }
};