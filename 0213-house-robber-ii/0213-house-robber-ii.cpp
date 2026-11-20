class Solution {
public:
    int n;
    int dp[101];
    int solve(vector<int>& nums , int start , int end){
        if(start>end){
            return 0;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        int take=0,skip=0;
        take=take+nums[start]+solve(nums,start+2,end);
        skip=skip+solve(nums,start+1,end);
        return dp[start]=max(take,skip);
    }

    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        memset(dp,-1,sizeof(dp));
        int way1=solve(nums,0,n-2);

        

        memset(dp,-1,sizeof(dp));
        int way2=solve(nums,1,n-1);

        return max(way1,way2);
        
    }
};