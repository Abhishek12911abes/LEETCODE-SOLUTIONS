class Solution {
public:
    // Pattern -> Min Max Dp
    // int solve(vector<int>& nums , int i , int j){
    //     if(i>j){
    //         return 0;
    //     }
    //     if(i==j){
    //         return nums[i];
    //     }
    //     int ithIdxTake=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
    //     int jthIdxTake=nums[j]+min(solve(nums,i,j-2),solve(nums,i+1,j-1));

    //     return max(ithIdxTake,jthIdxTake);
    // }
    int dp[21][21];
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

        int take_ith=nums[i]-solve(nums,i+1,j);
        int take_jth=nums[j]-solve(nums,i,j-1);

        return dp[i][j]=max(take_ith,take_jth);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        // int totalScore=accumulate(begin(nums),end(nums),0);
        // int P1Score=solve(nums,0,n-1);
        // int P2Score=totalScore-P1Score;

        // return P1Score-P2Score>=0;
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n-1)>=0;
        
    }
};