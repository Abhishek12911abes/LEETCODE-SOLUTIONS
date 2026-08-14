class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int score1 = 0;
        int score2 = 0;

        // Pattern 1: 010101...
        // Pattern 2: 101010...
        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {
                // Even index
                if (s[i] == '1')
                    score1++;

                if (s[i] == '0')
                    score2++;
            }
            else {
                // Odd index
                if (s[i] == '0')
                    score1++;

                if (s[i] == '1')
                    score2++;
            }
        }

        return min(score1, score2);
    }
};