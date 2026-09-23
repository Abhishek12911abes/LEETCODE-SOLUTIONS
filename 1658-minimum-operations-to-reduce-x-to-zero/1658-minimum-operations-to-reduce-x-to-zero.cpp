class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        if(x == 0) return 0;

        int totalSum = accumulate(begin(nums), end(nums), 0);
        int target = totalSum - x;

        if(target < 0) return -1;

        int i = 0, j = 0;
        int maxLen = -1;
        int sum = 0;

        while(j < n) {
            sum += nums[j];

            while(i <= j && sum > target) {
                sum -= nums[i];
                i++;
            }

            if(sum == target)
                maxLen = max(maxLen, j - i + 1);

            j++;
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};