class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string smallest;
        int n = s.size();
        int oneCount = 0;
        int i = 0, j = 0;
        int minLen = INT_MAX;
        while (j < n) {
            if (s[j] == '1')
                oneCount++;
            while (oneCount >= k) {

                int len = j - i + 1;
                string temp = s.substr(i, len);

                if (len < minLen || (len == minLen && temp < smallest)) {
                    minLen = len;
                    smallest = temp;
                }

                if (s[i] == '1') {
                    oneCount--;
                }

                i++;
            }
            j++;
        }
        return smallest;
    }
};