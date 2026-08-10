class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);

        // Calculate total points for every number
        for(int x : nums) {
            points[x] += x;
        }

        vector<int> dp(maxi + 1, 0);

        dp[0] = 0;

        if(maxi >= 1)
            dp[1] = points[1];

        for(int i = 2; i <= maxi; i++) {

            // Don't take i
            int skip = dp[i - 1];

            // Take i
            int take = points[i] + dp[i - 2];

            dp[i] = max(take, skip);
        }

        return dp[maxi];
    }
};