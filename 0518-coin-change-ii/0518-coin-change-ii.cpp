class Solution {
public:
    int n;
    int dp[5001][301];
    int solve(vector<int>& coins, int amount , int idx){
        if(idx>=n || amount<0){
            return 0;
        }
        if(amount==0){
            return 1;
        }
        if(dp[amount][idx]!=-1){
            return dp[amount][idx];
        }
        int take=solve(coins,amount-coins[idx],idx);
        int skip=solve(coins,amount,idx+1);

        return  dp[amount][idx]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(coins,amount,0);
        
    }
};