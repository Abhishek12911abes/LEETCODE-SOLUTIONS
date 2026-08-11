class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(vector<int>& nums , int currIdx , int prevIdx){
        if(currIdx>=n){
            return 0;
        }
        if(dp[currIdx][prevIdx+1]!=-1){
            return dp[currIdx][prevIdx+1];
        }
        int take=0,skip=0;

        skip=solve(nums,currIdx+1,prevIdx);

        if(prevIdx==-1 || nums[currIdx]>nums[prevIdx]){
            take=1+solve(nums,currIdx+1,currIdx);
        }

        return dp[currIdx][prevIdx+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();

        memset(dp,-1,sizeof(dp));

        return solve(nums,0,-1);
        
    }
};