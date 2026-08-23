class Solution {
public:
    // int dp[10001];
    // int solve(vector<int>& nums, int n, long long idx) {
    //     if (idx == n - 1) {
    //         return 0;
    //     }
    //     if (idx >= n) {
    //         return INT_MAX;
    //     }
    //     if(dp[idx]!=-1){
    //         return dp[idx];
    //     }
    //     int minMoves = INT_MAX;
    //     for (int i = 1; i <= nums[idx]; i++) {
    //         int moves = solve(nums, n, idx + i);
    //         if (moves != INT_MAX) {
    //             minMoves = min(minMoves, 1 + moves);
    //         }
    //     }
    //     return dp[idx]=minMoves;
    // }
    int jump(vector<int>& nums) {
        int n = nums.size();
        // memset(dp,-1,sizeof(dp));
        // return solve(nums, n, 0);

        // Bottom Up (Tabulation)

        // State defn - dp[i]=min number of steps to move from index 0 to index i;
        vector<int>dp(n,INT_MAX);
        dp[0]=0;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(j+nums[j]>=i){
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
        }
        return dp[n-1];

    }
};