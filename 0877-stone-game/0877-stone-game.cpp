class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums , int i , int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ith_idx=nums[i]-solve(nums,i+1,j);
        int jth_idx=nums[j]-solve(nums,i,j-1);

        return  dp[i][j]=max(ith_idx,jth_idx);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,n-1)>=0;

    }
};