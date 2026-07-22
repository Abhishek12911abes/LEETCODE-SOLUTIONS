class Solution {
public:
    // int n;
    // vector<vector<int>> dp;

    // int solve(int i, int j, vector<vector<int>>& matrix) {
    //     if (i >= n || j < 0 || j >= n)
    //         return INT_MAX / 2;

    //     if (i == n - 1)
    //         return matrix[i][j];

    //     if (dp[i][j] != INT_MAX)
    //         return dp[i][j];

    //     int leftDiagonal = solve(i + 1, j - 1, matrix);
    //     int down = solve(i + 1, j, matrix);
    //     int rightDiagonal = solve(i + 1, j + 1, matrix);

    //     return dp[i][j] = matrix[i][j] +
    //                       min({leftDiagonal, down, rightDiagonal});
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // n = matrix.size();

        // // Recursion + Memoization

        // dp.assign(n, vector<int>(n, INT_MAX));

        // int ans = INT_MAX;

        // for (int j = 0; j < n; j++) {
        //     ans = min(ans, solve(0, j, matrix));
        // }

        // return ans;

         int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n));

        // Base case: last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // Fill from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {

                int leftDiagonal = (j > 0) ? dp[i + 1][j - 1] : INT_MAX / 2;
                int down = dp[i + 1][j];
                int rightDiagonal = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX / 2;

                dp[i][j] = matrix[i][j] + min({leftDiagonal, down, rightDiagonal});
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;

    }
};