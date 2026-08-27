class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];

        int maxSum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }

        return max(abs(maxSum), abs(minSum));
    }
};