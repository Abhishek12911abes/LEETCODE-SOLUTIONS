class Solution {
public:
    // Pattern -> Min Max Dp
    int solve(vector<int>& nums , int i , int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        int ithIdxTake=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int jthIdxTake=nums[j]+min(solve(nums,i,j-2),solve(nums,i+1,j-1));

        return max(ithIdxTake,jthIdxTake);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int totalScore=accumulate(begin(nums),end(nums),0);
        int P1Score=solve(nums,0,n-1);
        int P2Score=totalScore-P1Score;

        return P1Score-P2Score>=0;
        
    }
};