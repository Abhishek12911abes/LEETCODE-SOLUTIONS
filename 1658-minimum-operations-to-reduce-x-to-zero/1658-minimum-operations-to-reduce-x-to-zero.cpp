// class Solution {
// public:
//     int minOperations(vector<int>& nums, int x) {
//         int n = nums.size();

//         int totalSum = 0;
//         for (int num : nums) {
//             totalSum += num;
//         }

//         int target = totalSum - x;

//         // If we need to keep an empty subarray
//         if (target == 0) return n;

//         unordered_map<int, int> mp;

//         // prefixSum -> index
//         mp[0] = -1;

//         int sum = 0;
//         int maxLen = -1;

//         for (int j = 0; j < n; j++) {
//             sum += nums[j];

//             int needed = sum - target;

//             if (mp.count(needed)) {
//                 maxLen = max(maxLen, j - mp[needed]);
//             }

//             // Store first occurrence only
//             if (!mp.count(sum)) {
//                 mp[sum] = j;
//             }
//         }

//         return maxLen == -1 ? -1 : n - maxLen;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;

        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        if (target == 0)
            return n;

        if (target < 0)
            return -1;

        int i = 0;
        int sum = 0;
        int maxLen = -1;

        for (int j = 0; j < n; j++) {

            sum += nums[j];

            while (sum > target && i <= j) {
                sum -= nums[i];
                i++;
            }

            if (sum == target) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};