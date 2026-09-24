class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>& nums , int start , int end){
        if(start>end){
            return 0;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        int take=nums[start]+solve(nums,start+2,end);

        int skip=solve(nums,start+1,end);

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
        dp.resize(n+1,-1);

        int idx0=solve(nums,0,n-2);

        dp.clear();

        dp.resize(n+1,-1);
        
        int idx1=solve(nums,1,n-1);

        return max(idx0,idx1);


        
    }
};