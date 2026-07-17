class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minLen = INT_MAX;
        int pos = -1;

        // pehle sabse CHHOTI string dhundo (longest common prefix kabhi
        // shortest string se lamba nahi ho sakta)
        for (int i = 0; i < n; i++) {
            if (strs[i].size() < minLen) {
                minLen = strs[i].size();
                pos = i;
            }
        }

        string ans;
        for (int j = 0; j < strs[pos].size(); j++) {
            char ch = strs[pos][j];

            // ab check karo ki SABHI strings ke SAME index 'j' pe
            // ye same character 'ch' hai ki nahi
            bool allMatch = true;
            for (int i = 0; i < n; i++) {
                if (strs[i][j] != ch) {   // sirf index j check karo, poori string nahi
                    allMatch = false;
                    break;
                }
            }

            if (!allMatch) {
                return ans;   // yahan tak jo match hua wahi return karo
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};