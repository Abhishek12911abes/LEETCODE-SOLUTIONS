class Solution {
public:
    int n;
    int dp[100005][2][2];
    int solve(vector<int>& prices, int idx, int buy, int cap) {

        if (idx >= n || cap == 0) {
            return 0;
        }

        if (dp[idx][buy][cap] != -1) {
            return dp[idx][buy][cap];
        }

        int take, skip;

        if (buy) {
            // Buy
            take = -prices[idx] + solve(prices, idx + 1, 0, cap);

            // Don't buy
            skip = solve(prices, idx + 1, 1, cap);
        }
        else {
            // Sell
            take = prices[idx] + solve(prices, idx + 1, 1, cap - 1);

            // Don't sell
            skip = solve(prices, idx + 1, 0, cap);
        }

        return dp[idx][buy][cap] = max(take, skip);
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        memset(dp, -1, sizeof(dp));

        return solve(prices, 0, 1, 1);
    }
};