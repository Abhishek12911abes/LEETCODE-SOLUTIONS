class Solution {
public:
    // int dp[46];
    // int solve(int n){
    //     if(n<0){
    //         return 0;
    //     }
    //     if(n==0){
    //         return 1;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int oneStep=solve(n-1);
    //     int twoStep=solve(n-2);

    //     return dp[n]=oneStep+twoStep;
    // }
    int climbStairs(int n) {
        // memset(dp,-1,sizeof(dp));
        // return solve(n);

        vector<int> dp(n + 1);
        if (n == 0)
            return 0;
        dp[0] = 0;
        if (n == 1)
            return 1;
        dp[1] = 1;
        if (n == 2)
            return 2;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};