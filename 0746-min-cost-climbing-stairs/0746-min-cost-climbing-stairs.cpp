class Solution {
public:
    int dp[1001];
    int solve(int i , vector<int>& cost){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int cst1=cost[i]+solve(i+1,cost);
        int cst2=cost[i]+solve(i+2,cost);

        return dp[i]=min(cst1,cst2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        memset(dp,-1,sizeof(dp));

        int idx0=solve(0,cost);
        int idx1=solve(1,cost);

        return min(idx0,idx1);
        
    }
};