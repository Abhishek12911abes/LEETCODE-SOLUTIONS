class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i <= 9; i++) {
            mp[i] = mapping[i];
        }
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++) {
            int orgNo = nums[i];
            string temp = to_string(nums[i]);
            string s;
            for (char c : temp) {
                char ch = char(mp[(c - '0')]+'0');
                s+=ch;
            }
            int mappedNo = 0;
            for (char c : s) {
                mappedNo = mappedNo * 10 + (c - '0');
            }
            vec.push_back({mappedNo, orgNo});
        }

        stable_sort(begin(vec), end(vec), [&](auto a, auto b) {
            return a.first < b.first;
        });
        vector<int> ans;
        for (auto num : vec) {
            int b = num.second;
            ans.push_back(b);
        }
        return ans;
    }
};