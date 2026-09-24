class Solution {
public:
    int n;
    int dp[100001][2][2];
    int solve(vector<int>& prices , int idx , int buy , int maxLimit){
        if(idx>=n){
            return 0;
        }

        if(maxLimit==0){
            return 0;
        }

        if(dp[idx][buy][maxLimit]!=-1){
            return dp[idx][buy][maxLimit];
        }

        int take,skip;
        if(buy){
            take=-prices[idx]+solve(prices,idx+1,0,maxLimit);
            skip=solve(prices,idx+1,1,maxLimit);
        }
        else{
            take=prices[idx]+solve(prices,idx+1,1,maxLimit-1);
            skip=solve(prices,idx+1,0,maxLimit);
        }

        return dp[idx][buy][maxLimit]=max(take,skip);

    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        // 1 means we are buying 
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1,1);
        
    }
};