class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    // int N, M;
    // int dp[2001][2001][2];
    // int solve(int i, int prevVal, bool increasing) {
    //     if (i >= N) {
    //         return 1;
    //     }
    //     if(dp[i][prevVal][increasing]!=-1){
    //         return dp[i][prevVal][increasing];
    //     }
    //     ll ans = 0;
    //     if (increasing == true) {
    //         for (int j = prevVal + 1; j <= M; j++) {
    //             ans = (ans + solve(i + 1, j, false)) % MOD; // increasing
    //         }
    //     } else {
    //         for (int k = 1; k < prevVal; k++) {
    //             ans = (ans + solve(i + 1, k, true)) % MOD; // decreasing
    //         }
    //     }
    //     return dp[i][prevVal][increasing]=ans % MOD;
    // }
    int zigZagArrays(int n, int l, int r) {
    // Approach 1) Recursion + Memo
    //     N = n;
    //     M = r - l + 1;

    //     ll result = 0;
    //     memset(dp,-1,sizeof(dp));
    //     for (int startVal = 1; startVal <= M;
    //          startVal++) { // har index pe 1 se m tak value rakh skte ho
    //         result = (result + solve(1, startVal, true)) % MOD;  // increasing
    //         result = (result + solve(1, startVal, false)) % MOD; // decreasing
    //     }
    //     return result;

    // Approach 2) Bottom Up
    //  int N = n;
    //  int M = r-l+1;

    //     ll t[2001][2001][2];
    //     memset(t, 0, sizeof(t));

    //     //Base Case
    //     for(int prevVal = 1; prevVal <= M; prevVal++) {
    //         t[N][prevVal][0] = 1;
    //         t[N][prevVal][1] = 1;
    //     }

    //     for(int i = N-1; i >= 0; i--) {

    //         for(int prevVal = 1; prevVal <= M; prevVal++) {

    //             for(int nextVal = prevVal+1; nextVal <= M; nextVal++) {
    //                 t[i][prevVal][1] = (t[i][prevVal][1] + t[i+1][nextVal][0]) % MOD;
    //             }

    //             for(int nextVal = 1; nextVal < prevVal; nextVal++) {
    //                 t[i][prevVal][0] = (t[i][prevVal][0] + t[i+1][nextVal][1]) % MOD;
    //             }

    //         }
    //     }

    //     ll result = 0;

    //     for(int startVal = 1; startVal <= M; startVal++) {
    //         //a < b > c < d ...
    //         result = (result + t[1][startVal][1]) % MOD;

    //         //a > b < c > d...
    //         result = (result + t[1][startVal][0]) % MOD;
    //     }

    //     return result;

    //Approach-3 (Bottom Up + Prefix Sum)
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];

        //Base Case
        for(int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 0; i--) {

            vector<ll> prefDir0(M+1, 0);
            vector<ll> prefDir1(M+1, 0);

            for(int prevVal = 1; prevVal <= M; prevVal++) {
                
                prefDir0[prevVal] = (prefDir0[prevVal-1] + t[i+1][prevVal][0]) % MOD;

                prefDir1[prevVal] = (prefDir1[prevVal-1] + t[i+1][prevVal][1]) % MOD;

            }

            for(int prevVal = 1; prevVal <= M; prevVal++) {
                
                t[i][prevVal][1] = (prefDir0[M] - prefDir0[prevVal] + MOD) % MOD;

                t[i][prevVal][0] = prefDir1[prevVal-1];

            }
        }

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;

            //a > b < c > d...
            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;
    }
};