class Solution {
public:
    typedef long long ll;
    int n;
    ll dp[100001];
    ll solve(vector<vector<int>>& questions , int idx){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        ll take=0,skip=0;
        ll points=questions[idx][0];
        ll to_skip=questions[idx][1];
        take=take+points+solve(questions,idx+to_skip+1);
        skip=skip+solve(questions,idx+1);

        return dp[idx]=max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        memset(dp,-1,sizeof(dp));
        return solve(questions,0);
    }
};