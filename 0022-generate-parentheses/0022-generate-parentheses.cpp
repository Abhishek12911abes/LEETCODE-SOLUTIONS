class Solution {
public:
    void solve(int n, int open, int close,
               string &temp, vector<string> &ans) {

        // Base case
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        // We can add '(' if we haven't used all n
        if (open < n) {
            temp.push_back('(');

            solve(n, open + 1, close, temp, ans);

            temp.pop_back();   // backtracking
        }

        // We can add ')' only if there is an unmatched '('
        if (close < open) {
            temp.push_back(')');

            solve(n, open, close + 1, temp, ans);

            temp.pop_back();   // backtracking
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string temp = "";

        solve(n, 0, 0, temp, ans);

        return ans;
    }
};