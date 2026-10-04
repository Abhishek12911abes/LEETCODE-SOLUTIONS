class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool solve(string &s, int idx, int balance) {

        // Invalid state
        if (balance < 0) {
            return false;
        }

        // String completely processed
        if (idx == n) {
            return balance == 0;
        }

        // Already calculated
        if (dp[idx][balance] != -1) {
            return dp[idx][balance];
        }

        bool ans = false;

        if (s[idx] == '(') {

            ans = solve(s, idx + 1, balance + 1);

        }
        else if (s[idx] == ')') {

            ans = solve(s, idx + 1, balance - 1);

        }
        else { // '*'

            // '*' -> '('
            bool asOpen =
                solve(s, idx + 1, balance + 1);

            // '*' -> ')'
            bool asClose =
                solve(s, idx + 1, balance - 1);

            // '*' -> empty
            bool asEmpty =
                solve(s, idx + 1, balance);

            ans = asOpen || asClose || asEmpty;
        }

        return dp[idx][balance] = ans;
    }

    bool checkValidString(string s) {

        n = s.size();

        // balance can be at most n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(s, 0, 0);
    }
};