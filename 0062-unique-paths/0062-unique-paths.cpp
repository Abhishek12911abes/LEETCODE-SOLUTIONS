class Solution {
public:
    // int dp[101][101];
    // int solve(int i, int j, int m, int n) {
    //     if (i >= m || j >= n) {
    //         return 0;
    //     }
    //     if (i == m - 1 && j == n - 1) {
    //         return 1;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     int ways = 0;
    //     ways += solve(i, j + 1, m, n);
    //     ways += solve(i + 1, j, m, n);
    //     return dp[i][j] = ways;
    // }
    int uniquePaths(int m, int n) {
        // memset(dp, -1, sizeof(dp));
        // return solve(0, 0, m, n);

        // Bottom Up
        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0]=1;

        // filling first row
        for(int i=1;i<n;i++){
            dp[0][i]=1;
        }

        // filling first col
        for(int i=1;i<m;i++){
            dp[i][0]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};