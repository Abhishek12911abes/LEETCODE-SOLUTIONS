class Solution {
public:
    int n;
    int dp[501][501];
    int solve(vector<int>& nums , int i , int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1=nums[i]+solve(nums,i+1,j);
        int op2=nums[j]+solve(nums,i,j-1);

        int maxi1=max(op1,op2);

        int op3=nums[i]+solve(nums,i+2,j);
        int op4=nums[j]+solve(nums,i,j-2);

        int maxi2=max(op3,op4);

        return dp[i][j]=max(maxi1,maxi2);
    }
    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        int totalPiles=accumulate(begin(piles),end(piles),0);
        memset(dp,-1,sizeof(dp));
        return (totalPiles-solve(piles,0,n-1))>=0;
        
    }
};