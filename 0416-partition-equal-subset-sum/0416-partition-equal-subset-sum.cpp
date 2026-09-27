class Solution {
public:
    int n;
    int dp[20001][201];
    int solve(vector<int>& nums , int target , int idx){
        if(idx>=n || target<0){
            return false;
        }

        if(target==0){
            return true;
        }

        if(dp[target][idx]!=-1){
            return dp[target][idx];
        }

        int take=solve(nums,target-nums[idx],idx+1);
        int skip=solve(nums,target,idx+1);

        return dp[target][idx]= take || skip;

    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int totalSum=accumulate(begin(nums),end(nums),0);

        if(totalSum%2==1){
            return false;
        }

        int target=totalSum/2;

        memset(dp,-1,sizeof(dp));

        return solve(nums,target,0);
    }
};