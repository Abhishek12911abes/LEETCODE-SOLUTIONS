class Solution {
public:
    int n;
    int t[1000];
    int solve(vector<int>& cost , int idx){
        if(idx>=n){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }

        int oneStep=cost[idx]+solve(cost,idx+1);
        int twoStep=cost[idx]+solve(cost,idx+2);

        return t[idx]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(t,-1,sizeof(t));
        int zeroIndexCost=solve(cost,0);
        int oneIndexCost=solve(cost,1);

        return min(zeroIndexCost,oneIndexCost);
        
    }
};