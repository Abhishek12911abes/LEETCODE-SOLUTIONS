#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001];

    int solve(vector<int>& cost, int idx){
        
        // base case
        if(idx >= cost.size()) return 0;

        // already calculated
        if(dp[idx] != -1){
            return dp[idx];
        }

        int one_step = cost[idx] + solve(cost, idx+1);
        int two_step = cost[idx] + solve(cost, idx+2);

        return dp[idx] = min(one_step, two_step);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        memset(dp, -1, sizeof(dp));

        return min(solve(cost,0), solve(cost,1));
    }
};

int main(){
    vector<int> cost = {10,15,20};

    Solution obj;

    cout << obj.minCostClimbingStairs(cost);

    return 0;
}