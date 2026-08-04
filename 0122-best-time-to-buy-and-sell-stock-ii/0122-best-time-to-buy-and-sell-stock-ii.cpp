class Solution {
public:
    // int n;
    // int t[30001][2];
    // int solve(vector<int>& nums , int idx , int buy){
    //     if(idx>=n){
    //         return 0;
    //     }

    //     if(t[idx][buy]!=-1){
    //         return t[idx][buy];
    //     }

    //     int maxProfit=0;
    //     if(buy){
    //         maxProfit=max(-nums[idx]+solve(nums,idx+1,0),0+solve(nums,idx+1,1));
    //         // agar buy kiya hai toh agli baar sell krega ya toh buy hi nhi kiya hai toh val 1 hi rhegi
    //         //-nums[idx] isliye kiya taki aage jab sell hoga toh buy wali value minus hogi
    //     }
    //     else{
    //         maxProfit=max(nums[idx]+solve(nums,idx+1,1),0+solve(nums,idx+1,0));
    //         // agar sell kiya hai toh agli baar buy krega ya toh sell hi nhi kiya hai toh val 0 hi rhegi
    //         //nums[idx] isliye kiya taki profit milegi
    //     }
    //     return t[idx][buy]=maxProfit;
    // }
    int maxProfit(vector<int>& prices) {
        // n=prices.size();
        // // buy ki value 0 ya 1 ho skti hai 

        // // 0 matlab buy nhi kr skta hai
        // // 1 matlab buy kr skta hai

        // memset(t,-1,sizeof(t));
        // return solve(prices,0,1); // )th index pe ho matlab buy kr skte ho

        int n=prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][buy]=profit;

            }
        }
        return dp[0][1]; // at first day u can buy a stock;
    }
};