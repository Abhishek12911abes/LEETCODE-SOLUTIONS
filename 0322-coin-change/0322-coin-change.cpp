class Solution {
public:
    int n;
    int dp[13][10001];
    typedef long long ll;
    ll solve(vector<int>& coins , int amount , int idx){
        if(amount==0){
            return 0;
        }
        if(idx>=coins.size()){
            return INT_MAX;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        ll take=1+solve(coins,amount-coins[idx],idx);
        ll skip=solve(coins,amount,idx+1);

        return dp[idx][amount]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(coins,amount,0);
        return ans==INT_MAX?-1:ans;
        
    }
};