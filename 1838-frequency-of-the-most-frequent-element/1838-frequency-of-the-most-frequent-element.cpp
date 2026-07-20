class Solution {
public:
    bool canMake(vector<int>& nums, vector<long long>& prefix, int len, int k) {
        int n = nums.size();

        for (int i = len - 1; i < n; i++) {
            long long windowSum = prefix[i] - (i - len >= 0 ? prefix[i - len] : 0);
            long long target = 1LL * nums[i] * len;

            if (target - windowSum <= k)
                return true;
        }

        return false;
    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        int low = 1, high = n, ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(nums, prefix, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};