class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int groups = 1;
        int start = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[start] > k) {
                groups++;
                start = i;
            }
        }

        return groups;
    }
};