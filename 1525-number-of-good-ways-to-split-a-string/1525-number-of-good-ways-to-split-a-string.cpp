class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> leftmap;
        unordered_map<char, int> rightmap;
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            rightmap[s[i]]++;
        }
        for (int i = 0; i < n; i++) {
            leftmap[s[i]]++;
            rightmap[s[i]]--;
            if (rightmap[s[i]] == 0) {
                rightmap.erase(s[i]);
            }

            if (leftmap.size() == rightmap.size()) {
                count++;
            }
        }
        return count;
    }
};