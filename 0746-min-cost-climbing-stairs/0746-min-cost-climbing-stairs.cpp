class Solution {
public:
    int n;
    int dp[1001];
    int solve(vector<int>& cost , int idx){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int oneStep=cost[idx]+solve(cost,idx+1);
        int twoStep=cost[idx]+solve(cost,idx+2);

        return dp[idx]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();

        memset(dp,-1,sizeof(dp));
        
        int idx0=solve(cost,0);

        int idx1=solve(cost,1);

        return min(idx0,idx1);
        
    }
};