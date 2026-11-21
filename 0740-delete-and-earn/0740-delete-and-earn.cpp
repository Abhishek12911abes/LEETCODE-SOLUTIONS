class Solution {
public:
    int dp[10001];

    int solve(vector<int>& points, int val, int maxVal) {
        if(val > maxVal) {
            return 0;
        }

        if(dp[val] != -1) {
            return dp[val];
        }

        int take = points[val] + solve(points, val + 2, maxVal);
        int skip = solve(points, val + 1, maxVal);

        return dp[val] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(begin(nums), end(nums));

        vector<int> points(maxVal + 1, 0);

        for(int num : nums) {
            points[num] += num;
        }

        memset(dp, -1, sizeof(dp));

        return solve(points, 0, maxVal);
    }
};