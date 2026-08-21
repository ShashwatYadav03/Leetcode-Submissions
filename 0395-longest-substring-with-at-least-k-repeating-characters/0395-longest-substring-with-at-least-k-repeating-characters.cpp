class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length()<k) return 0;

        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        // Find a character that occurs less than k times
        for (auto it : freq) {
            if (it.second < k) {
                char bad = it.first;

                int ans = 0;
                string temp = "";

                // Split at the bad character
                for (char c : s) {
                    if (c == bad) {
                        ans = max(ans, longestSubstring(temp, k));
                        temp = "";
                    } else {
                        temp += c;
                    }
                }

                ans = max(ans, longestSubstring(temp, k));

                return ans;
            }
        }

        // Every character occurs at least k times
        return s.length();
    }
};