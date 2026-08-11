class Solution {
public:
    // int n;
    // int dp[2501][2501];
    // int solve(vector<int>& nums , int currIdx , int prevIdx){
    //     if(currIdx>=n){
    //         return 0;
    //     }
    //     if(dp[currIdx][prevIdx+1]!=-1){
    //         return dp[currIdx][prevIdx+1];
    //     }
    //     int take=0,skip=0;

    //     skip=solve(nums,currIdx+1,prevIdx);

    //     if(prevIdx==-1 || nums[currIdx]>nums[prevIdx]){
    //         take=1+solve(nums,currIdx+1,currIdx);
    //     }

    //     return dp[currIdx][prevIdx+1]=max(take,skip);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        // memset(dp,-1,sizeof(dp));

        // return solve(nums,0,-1);

        vector<int>dp(n+1,1);

        int maxLen=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxLen=max(maxLen,dp[i]);
                }
            }
        }
        return maxLen;
        
    }
};