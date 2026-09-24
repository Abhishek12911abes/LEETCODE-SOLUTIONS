class Solution {
public:
    int n;
    int dp[10001][13];
    int solve(vector<int>& coins , int amount , int idx){
        if(amount==0){
            return 0;
        }
        if(amount<0 || idx>=n){
            return INT_MAX;
        }
        if(dp[amount][idx]!=-1){
            return dp[amount][idx];
        }
        int take=solve(coins,amount-coins[idx],idx);
        if(take != INT_MAX)
            take += 1;
        int skip=solve(coins,amount,idx+1);

        return dp[amount][idx]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();


        memset(dp,-1,sizeof(dp));

        int ans=solve(coins,amount,0);

        return ans==INT_MAX?-1:ans;
        
    }
};