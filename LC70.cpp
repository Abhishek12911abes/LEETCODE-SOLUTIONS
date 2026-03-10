#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[46];

    int solve(int n){
        if(n < 0) return 0;

        if(dp[n] != -1){
            return dp[n];
        }

        if(n == 0) return 1;  // 1 way to stay at ground

        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return dp[n] = one_step + two_step;
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));   // array, value, size
        return solve(n);
    }
};

int main(){
    int n;
    cin >> n;

    Solution obj;

    cout << obj.climbStairs(n);

    return 0;
}