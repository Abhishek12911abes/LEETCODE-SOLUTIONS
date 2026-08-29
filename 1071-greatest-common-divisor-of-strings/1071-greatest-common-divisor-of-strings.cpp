class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        int n = str2.size();

        for (int i = n; i >= 1; i--) {

            string temp1 = str2.substr(0, i);

            bool canMake = true;

            // Check str1
            if (str1.size() % i != 0) {
                continue;
            }

            int p = 0;

            while (p < str1.size()) {
                string temp2 = str1.substr(p, i);

                if (temp1 != temp2) {
                    canMake = false;
                    break;
                }

                p += i;
            }

            if (!canMake) {
                continue;
            }

            // Check str2
            if (str2.size() % i != 0) {
                continue;
            }

            p = 0;

            while (p < str2.size()) {
                string temp2 = str2.substr(p, i);

                if (temp1 != temp2) {
                    canMake = false;
                    break;
                }

                p += i;
            }

            if (canMake) {
                return temp1;
            }
        }

        return "";
    }
};