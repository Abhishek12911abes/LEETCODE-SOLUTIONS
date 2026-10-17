class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> digitSum;
        for (int num : nums) {
            int temp = num;
            int sum = 0;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            digitSum.push_back({sum, num});
        }
        sort(begin(digitSum), end(digitSum), [&](auto a, auto b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        unordered_map<int, int> mp; // ye map krega nums ke original number ko
                                    // uske corresponding index se

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        int minSwaps=0;
        for(int i=0;i<n;i++){
            int expectedNo = digitSum[i].second;
            int currNo=nums[i];

            if(currNo == expectedNo) continue;

            int j=mp[expectedNo]; // ye bataege ki expected no ka correct idx kaha hona chahie

            swap(nums[i],nums[j]);

            mp[expectedNo]=i;
            mp[currNo]=j;

            minSwaps++;
        }
        return minSwaps;
    }
};