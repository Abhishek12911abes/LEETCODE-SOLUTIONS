class Solution {
public:
    typedef long long ll;

    long long countCommas(long long n) {

        if(n <= 999) {
            return 0;
        }

        ll type1=0, type2=0, type3=0, type4=0, type5=0;

        if(n < 1e6) {

            type1 = n - 1000 + 1;

            return type1;
        }

        else if(n < 1e9) {

            type2 += 1e6 - 1000;

            type2 += 2 * (n - 1000000 + 1);

            return type2;
        }

        else if(n < 1e12) {

            type3 += 1e6 - 1000;

            type3 += 2 * (1e9 - 1e6);

            type3 += 3 * (n - 1000000000LL + 1);

            return type3;
        }

        else if(n < 1e15) {

            type4 += 1e6 - 1000;

            type4 += 2 * (1e9 - 1e6);

            type4 += 3 * (1000000000000LL - 1000000000LL);

            type4 += 4 * (n - 1000000000000LL + 1);

            return type4;
        }

        else {

            type5 += 1e6 - 1000;

            type5 += 2 * (1e9 - 1e6);

            type5 += 3 * (1000000000000LL - 1000000000LL);

            type5 += 4 * (1000000000000000LL - 1000000000000LL);

            type5 += 5 * (n - 1000000000000000LL + 1);

            return type5;
        }

        return -1;
    }
};