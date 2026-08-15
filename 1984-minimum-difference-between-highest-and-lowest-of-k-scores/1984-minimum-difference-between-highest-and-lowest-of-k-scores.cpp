class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.rbegin(), nums.rend());

        int i = 0;
        int minDiff = INT_MAX;

        for (int j = 0; j < n; j++) {

            if (j - i + 1 == k) {
                minDiff = min(minDiff, nums[i] - nums[j]);
                i++;
            }
        }

        return minDiff;
    }
};