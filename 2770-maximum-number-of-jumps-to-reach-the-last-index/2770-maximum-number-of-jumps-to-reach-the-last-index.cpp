class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& nums, int target, int currIdx) {

        if (currIdx == n - 1) {
            return 0;
        }

        if (dp[currIdx] != -1) {
            return dp[currIdx];
        }

        int maxi = INT_MIN;

        for (int nextIdx = currIdx + 1; nextIdx < n; nextIdx++) {

            long long diff =
                (long long)nums[nextIdx] - nums[currIdx];

            if (abs(diff) <= target) {

                int ans = solve(nums, target, nextIdx);

                if (ans != INT_MIN) {
                    maxi = max(maxi, 1 + ans);
                }
            }
        }

        return dp[currIdx] = maxi;
    }

    int maximumJumps(vector<int>& nums, int target) {

        n = nums.size();

        dp.assign(n, -1);

        int ans = solve(nums, target, 0);

        return ans == INT_MIN ? -1 : ans;
    }
};