class Solution {
public:
    bool solve(int n, int first, int prev) {

        // Current player cannot make a move
        if(n < prev) {
            return false;
        }

        // Remove the required stones
        n -= prev;

        // Next turn requires one fewer stone
        return !solve(n, !first, prev - 1);
    }

    bool canAliceWin(int n) {
        if(n < 10) {
            return false;
        }

        return solve(n, 1, 10);
    }
};