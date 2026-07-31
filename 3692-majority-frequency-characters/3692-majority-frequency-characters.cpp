class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> cnt(26, 0);

        // Count frequency of each character
        for (char c : s)
            cnt[c - 'a']++;

        // frequency -> characters
        unordered_map<int, string> groups;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0)
                groups[cnt[i]].push_back(char('a' + i));
        }

        int maxGroupSize = 0;
        int chosenFreq = 0;
        string ans;

        for (auto &it : groups) {
            int freq = it.first;
            string chars = it.second;

            if ((int)chars.size() > maxGroupSize ||
                ((int)chars.size() == maxGroupSize && freq > chosenFreq)) {
                maxGroupSize = chars.size();
                chosenFreq = freq;
                ans = chars;
            }
        }

        return ans;
    }
};