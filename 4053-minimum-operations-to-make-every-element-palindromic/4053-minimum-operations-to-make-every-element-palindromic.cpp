class Solution {
public:

    long long makePalindrome(string s, bool odd) {
        string t = s;

        int i = odd ? s.size() - 2 : s.size() - 1;

        while (i >= 0) {
            t += s[i];
            i--;
        }

        return stoll(t);
    }

    long long minOperations(vector<int>& nums) {

        // pal[0] = even palindromes
        // pal[1] = odd palindromes
        static vector<long long> pal[2];

        // Precompute only once
        if (pal[0].empty() && pal[1].empty()) {

            for (long long i = 1; i <= 100000; i++) {

                string s = to_string(i);

                // Even length palindrome
                long long p1 = makePalindrome(s, false);
                pal[p1 % 2].push_back(p1);

                // Odd length palindrome
                long long p2 = makePalindrome(s, true);
                pal[p2 % 2].push_back(p2);
            }

            sort(pal[0].begin(), pal[0].end());
            sort(pal[1].begin(), pal[1].end());
        }

        long long ans = 0;

        for (long long x : nums) {

            // x can only reach palindrome with same parity
            vector<long long>& v = pal[x % 2];

            // First palindrome >= x
            auto it = lower_bound(v.begin(), v.end(), x);

            long long best = LLONG_MAX;

            // Palindrome >= x
            if (it != v.end()) {
                best = min(best, *it - x);
            }

            // Palindrome < x
            if (it != v.begin()) {
                --it;
                best = min(best, x - *it);
            }

            // Each operation changes by 2
            ans += best / 2;
        }

        return ans;
    }
};