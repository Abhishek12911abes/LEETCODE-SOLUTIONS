class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1) {
            return s;
        }
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string ans;
        for (int i = 0; i < 26; i++) {
            if (freq[i]>0) {
                char ch = i + 'a';
                int times = freq[i] / 2;
                int left = freq[i] % 2;
                freq[i]=freq[i]-(2*times);
                while (times--) {
                    ans += ch;
                }
            }
        }

        string t = ans;
        reverse(begin(t), end(t));

        string rem;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                rem += (i + 'a');
            }
        }

        return ans + rem + t;
    }
};