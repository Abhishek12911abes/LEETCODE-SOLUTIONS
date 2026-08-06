class Solution {
public:
    // int dp[100001][2][3];
    // int n;
    // int solve(vector<int>& prices , int idx , int buy , int cap){
    //     if(idx>=n || cap==0){
    //         return 0;
    //     }
    //     if(dp[idx][buy][cap]!=-1){
    //         return dp[idx][buy][cap];
    //     }
    //     int maxProfit=0;
    //     if(buy){
    //         maxProfit=max(-prices[idx]+solve(prices,idx+1,0,cap) , 0 + solve(prices,idx+1,1,cap));
    //     }
    //     else{
    //         maxProfit=max(prices[idx]+solve(prices,idx+1,1,cap-1), 0 + solve(prices,idx+1,0,cap));
    //         // agar buy and sell dono kr dega tab jake cap-1 hoga
    //     }

    //     return dp[idx][buy][cap]=maxProfit;
    // }
    int maxProfit(vector<int>& prices) {
        // Approach 1) Recur + Memo

        // n=prices.size();
        // memset(dp,-1,sizeof(dp));
        // return solve(prices,0,1,2); // prices,idx,buy,capacity;
        // 1 means buy and 0 means sell

        // Approach 2) Tabulation

        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        int maxProfit=0;
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){ // cap 0 pe return 0 isliye cap ko 1 se strt kiya
                    if(buy==1){
                        maxProfit=max(-prices[idx]+dp[idx+1][0][cap] , 0+dp[idx+1][1][cap]);
                    }
                    else{
                        maxProfit=max(prices[idx]+dp[idx+1][1][cap-1] , 0 + dp[idx+1][0][cap]);
                    }

                    dp[idx][buy][cap]=maxProfit;
                }
            }
        }
        return dp[0][1][2];

        
        
    }
};