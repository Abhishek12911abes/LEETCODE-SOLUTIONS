class Solution {
public:
    int n;
    int dp[1001][1001];
    int lis(vector<int>& nums , int curr , int prev){
        if(curr>=n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take=0,skip=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            take=1+lis(nums,curr+1,curr);
        }
        skip=lis(nums,curr+1,prev);
        return dp[curr][prev+1]=max(skip,take);
    }
    bool canBeIncreasing(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));

        int s=lis(nums,0,-1);
        return n-s<=1;
        
    }
};