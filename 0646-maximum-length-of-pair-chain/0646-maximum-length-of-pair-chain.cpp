class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>& nums , int currIdx , int prevIdx){
        if(currIdx==nums.size()){
            return 0;
        }
        if(dp[currIdx][prevIdx+1]!=-1){
            return dp[currIdx][prevIdx+1];
        }
        int skip=solve(nums,currIdx+1,prevIdx);
        int take=0;
        if(prevIdx==-1 || nums[currIdx][0]>nums[prevIdx][1]){
            take=1+solve(nums,currIdx+1,currIdx);
        }
        return dp[currIdx][prevIdx+1]=max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(dp,-1,sizeof(dp));
        return solve(pairs,0,-1);

    }
};