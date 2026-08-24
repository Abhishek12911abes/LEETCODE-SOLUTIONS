class Solution {
public:
    bool isVowel(char c, char d) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') &&
               (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u');
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = isVowel(words[0][0], words[0][words[0].size() - 1]);
        for (int i = 1; i < n; i++) {
            if (isVowel(words[i][0], words[i][words[i].size() - 1])) {
                prefixSum[i] = prefixSum[i - 1]+1;
            }
            else{
                prefixSum[i]=prefixSum[i-1];
            }
        }
        // for (int num : prefixSum) {
        //     cout << num << " ";
        // }
        int k = queries.size();
        vector<int> ans;
        for (auto query : queries) {
            int l = query[0];
            int r = query[1];
            if (l == 0) {
                ans.push_back(prefixSum[r]);
            } else {
                int val = prefixSum[r] - prefixSum[l - 1];
                ans.push_back(val);
            }
        }
        return ans;
    }
};