class Solution {
public:
    vector<vector<int>>dp;
    int solve(int n , int num){
        if(n==0){
            return 0;
        }
        if(n<0 || 1LL*num*num>n){
            return INT_MAX;
        }
        if(dp[n][num]!=-1){
            return dp[n][num];
        }
        int take=solve(n-(1LL*num*num),num);
        if(take!=INT_MAX){
            take=take+1;
        }

        int skip=solve(n,num+1);

        return dp[n][num]=min(take,skip);

    }
    int numSquares(int n) {
        dp.assign(n+1,vector<int>(sqrt(n)+2,-1));
        return solve(n,1);
    }
};