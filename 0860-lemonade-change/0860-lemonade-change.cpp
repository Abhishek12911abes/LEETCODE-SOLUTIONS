class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int change = 0;
        int five = 0, ten = 0, twenty = 0;  // initialize

        for(int i = 0; i < n; i++) {

            int cost = bills[i];
            int remaining = cost - 5;

            if(bills[i] == 5) {
                five++;
            }

            else if(bills[i] == 10) {

                // Need one 5 for change
                if(five < 1) {
                    return false;
                }

                five--;
                ten++;
            }

            else {  // bills[i] == 20

                // Need 15 change
                // Prefer 10 + 5
                if(ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                }
                else if(five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }

                twenty++;
            }
        }

        return true;
    }
};