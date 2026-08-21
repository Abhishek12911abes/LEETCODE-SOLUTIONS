class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int truckSize) {

        sort(begin(nums), end(nums), [](auto &a, auto &b) {
            return a[1] > b[1];
        });

        int take = 0;
        int maxi = 0;

        for(auto &i : nums) {

            if(take + i[0] <= truckSize) {
                take += i[0];
                maxi += i[0] * i[1];
            }
            else {
                int remain = truckSize - take;
                maxi += remain * i[1];
                break;
            }
        }

        return maxi;
    }
};