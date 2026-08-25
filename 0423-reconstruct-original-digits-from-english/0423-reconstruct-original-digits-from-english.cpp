class Solution {
public:
    string originalDigits(string s) {
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> count(10, 0);

        // Unique characters
        count[0] = freq['z' - 'a']; // zero
        count[2] = freq['w' - 'a']; // two
        count[4] = freq['u' - 'a']; // four
        count[6] = freq['x' - 'a']; // six
        count[8] = freq['g' - 'a']; // eight

        // Remaining digits
        count[1] = freq['o' - 'a'] - count[0] - count[2] - count[4];
        count[3] = freq['h' - 'a'] - count[8];
        count[5] = freq['f' - 'a'] - count[4];
        count[7] = freq['s' - 'a'] - count[6];

        count[9] = freq['i' - 'a'] 
                 - count[5] 
                 - count[6] 
                 - count[8];

        string ans;

        for (int digit = 0; digit <= 9; digit++) {
            while (count[digit]--) {
                ans += char('0' + digit);
            }
        }

        return ans;
    }
};