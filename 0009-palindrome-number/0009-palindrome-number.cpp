class Solution {
public:
    bool isPalindrome(int x) {
        long long int original = x;
       long long int reverse = 0;
       while(x>0){
         int n = x%10;
         reverse = (reverse*10)+ n; 
         x=x/10;
       }
       if(reverse == original) return true;
       else return false;
    }
};