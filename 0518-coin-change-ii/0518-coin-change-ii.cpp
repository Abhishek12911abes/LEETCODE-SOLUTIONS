class Solution {
public:
    int n;
    int dp[301][5001];
    int solve(vector<int>& coins , int amount , int idx){
        if(amount==0){
            return 1;
        }
        if(idx>=n || amount<0){
            return 0;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int take=solve(coins,amount-coins[idx],idx);
        int skip=solve(coins,amount,idx+1);

        return dp[idx][amount]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(coins,amount,0);
        return ans;
        
    }
};