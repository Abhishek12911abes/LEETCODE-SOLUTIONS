class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<long long> dp(n + 1, LLONG_MAX);

        dp[n] = 0;

        for(int idx = n - 1; idx >= 0; idx--) {

            long long way1 = LLONG_MAX, way2 = LLONG_MAX, way3 = LLONG_MAX;

            if(idx + 1 <= n) {
                int j = idx + 1;
                way1 = costs[j-1] + (j-idx)*(j-idx) + dp[idx+1];
            }

            if(idx + 2 <= n) {
                int j = idx + 2;
                way2 = costs[j-1] + (j-idx)*(j-idx) + dp[idx+2];
            }

            if(idx + 3 <= n) {
                int j = idx + 3;
                way3 = costs[j-1] + (j-idx)*(j-idx) + dp[idx+3];
            }

            dp[idx] = min({way1, way2, way3});
        }

        return dp[0];
    }
};