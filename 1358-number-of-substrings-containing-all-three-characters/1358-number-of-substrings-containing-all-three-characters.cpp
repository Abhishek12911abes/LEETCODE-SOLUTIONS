class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int result = 0;

        int counta = 0, countb = 0, countc = 0;
        int i = 0, j = 0;

        while (j < n) {
            counta = (s[j] == 'a') ? counta + 1 : counta;
            countb = (s[j] == 'b') ? countb + 1 : countb;
            countc = (s[j] == 'c') ? countc + 1 : countc;

            while(counta>=1 && countb>=1 && countc>=1){
                result+=n-j;
                counta = (s[i] == 'a') ? counta - 1 : counta;
                countb = (s[i] == 'b') ? countb - 1 : countb;
                countc = (s[i] == 'c') ? countc - 1 : countc;
                i++;
            }
            j++;
        }

        return result;
    }
};