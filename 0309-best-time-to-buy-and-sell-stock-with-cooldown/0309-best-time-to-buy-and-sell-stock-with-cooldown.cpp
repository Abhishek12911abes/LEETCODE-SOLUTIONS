class Solution {
public:
    int n;
    int dp[5001][2];
    int solve(vector<int>& prices , int idx , int buy){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int take=0,skip=0;
        if(buy){
            take=-prices[idx]+solve(prices,idx+1,0);
            skip=solve(prices,idx+1,1);
        }
        else{
            take=prices[idx]+solve(prices,idx+2,1);
            skip=solve(prices,idx+1,0);
        }
        return dp[idx][buy]=max(take,skip);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();

        memset(dp,-1,sizeof(dp));

        return solve(prices,0,1);
        
    }
};