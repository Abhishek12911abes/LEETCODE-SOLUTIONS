class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int majElem1 = -1, majElem2 = -1;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == majElem1) {
                count1++;
            } else if (nums[i] == majElem2) {
                count2++;
            } else if (count1 == 0) {
                count1 = 1;
                majElem1 = nums[i];
            } else if (count2 == 0) {
                count2 = 1;
                majElem2 = nums[i];
            } else {
                count1--, count2--;
            }
        }
        int elem1 = 0, elem2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == majElem1) {
                elem1++;
            } else if (nums[i] == majElem2) {
                elem2++;
            }
        }

        vector<int> ans;

        if (elem1 > n / 3)
            ans.push_back(majElem1);

        if (elem2 > n / 3)
            ans.push_back(majElem2);

        return ans;
    }
};