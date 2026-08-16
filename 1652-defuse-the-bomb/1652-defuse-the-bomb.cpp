class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;

        // Duplicate array
        for (int i = 0; i < n; i++) {
            code.push_back(code[i]);
        }

        // Prefix sum
        vector<int> prefix(2 * n + 1, 0);

        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + code[i];
        }

        // k > 0
        if (k > 0) {
            for (int i = 0; i < n; i++) {

                // next k elements
                int l = i + 1;
                int r = i + k;

                ans[i] = prefix[r + 1] - prefix[l];
            }
        }

        // k < 0
        else {
            k = -k;

            for (int i = 0; i < n; i++) {

                // previous k elements
                int l = i + n - k;
                int r = i + n - 1;

                ans[i] = prefix[r + 1] - prefix[l];
            }
        }

        return ans;
    }
};