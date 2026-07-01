class Solution {
public:
    int dp[1001][1001];
    int solve(string& s, string& t, int i, int j) {

        if (i == s.size() || j == t.size())
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if (s[i] == t[j])
            return dp[i][j]=1 + solve(s, t, i + 1, j + 1);

        return dp[i][j]=max(solve(s, t, i + 1, j), solve(s, t, i, j + 1));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string temp = s;
        reverse(begin(temp), end(temp));
        memset(dp,-1,sizeof(dp));
        return solve(s, temp, 0, 0);
    }
};