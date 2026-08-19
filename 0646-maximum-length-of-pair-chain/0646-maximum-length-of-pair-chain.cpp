class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<vector<int>>& nums , int idx , int prev){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take=0,skip=0;
        if(prev==-1 || nums[idx][0]>nums[prev][1]){
            take=1+solve(nums,idx+1,idx);
        }
        skip=solve(nums,idx+1,prev);
        return dp[idx][prev+1]=max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n =pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(begin(pairs),end(pairs));
        
        return solve(pairs,0,-1);
        
    }
};