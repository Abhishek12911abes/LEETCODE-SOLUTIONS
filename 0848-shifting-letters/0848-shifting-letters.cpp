class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long suffixSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            suffixSum = (suffixSum + shifts[i]) % 26;

            s[i] = 'a' + (s[i] - 'a' + suffixSum) % 26;
        }

        return s;
    }
};