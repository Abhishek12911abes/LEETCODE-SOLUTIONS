class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool allEven = true, allOdd = true;

        for (int num : nums1) {
            if (num % 2 == 1) {
                allEven = false;
            }
            else {
                allOdd = false;
            }
        }

        if (allEven || allOdd) {
            return true;
        }

        bool ans1 = false, ans2 = true;

        // Case 1:
        // Mixed parity mein saara EVEN banana impossible
        // because smallest ODD ko smaller ODD nahi milega.

        // Case 2:
        // Saara ODD banana

        set<int> st2;

        // Pehle saare ODD elements set mein daal do
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                st2.insert(nums1[i]);
            }
        }

        // Smallest ODD
        int smallestOdd = *st2.begin();

        for (int i = 0; i < n; i++) {

            // ODD already odd hai
            if (nums1[i] % 2 == 1)
                continue;

            int num = nums1[i];

            // EVEN - smallest ODD >= 1 hona chahiye
            if (num - smallestOdd < 1) {
                ans2 = false;
            }
        }

        return ans1 || ans2;
    }
};