class Solution {
public:
    int n;
    int dp[2][50001];
    int solve(vector<int>& prices , int fee , int buy , int idx){
        if(idx>=n){
            return 0;
        }
        if(dp[buy][idx]!=-1){
            return dp[buy][idx];
        }
        int take=0,skip=0;
        if(buy){
            take=-prices[idx]+solve(prices,fee,0,idx+1);
            skip=solve(prices,fee,1,idx+1);
        }
        else{
            take=prices[idx]-fee+solve(prices,fee,1,idx+1);
            skip=solve(prices,fee,0,idx+1);
        }
        return dp[buy][idx]=max(take,skip);
    }
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,fee,1,0);
        
    }
};