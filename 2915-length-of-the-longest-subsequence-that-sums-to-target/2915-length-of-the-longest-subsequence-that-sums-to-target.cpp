class Solution {
public:
    int n;
    int dp [1001] [1001];
    int solve(vector<int>& nums , int target , int idx){
        if(target==0){
            return 0;
        }
        if(idx>=n || target<0){
            return INT_MIN;
        }
        if (dp[idx][target ]!= -1 ){
            return dp[idx][target];
        }

        int take=1+solve(nums,target-nums[idx],idx+1);
        int skip=solve(nums,target,idx+1);

        return dp[idx][target] = max(take,skip);

    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,target,0);
        return ans<0?-1:ans;
    }
};