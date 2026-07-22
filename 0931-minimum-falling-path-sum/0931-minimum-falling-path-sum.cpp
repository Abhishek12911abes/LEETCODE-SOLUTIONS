class Solution {
public:
    int n;
    typedef long long ll;
    vector<vector<ll>> dp;
    ll solve(int i , int j , vector<vector<int>>& matrix){
        if(i>=n || j<0 || i<0 || j>=n){
            return LLONG_MAX;
        }
        if(i==n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=LLONG_MAX){
            return dp[i][j];
        }
        ll leftDiagonal=LLONG_MAX;
        ll down=LLONG_MAX;
        ll rightDiagonal=LLONG_MAX;
        if(i+1<n && j-1>=0){
            leftDiagonal=solve(i+1,j-1,matrix);
        }
        if(i+1<n){
            down=solve(i+1,j,matrix);
        }
        if(i+1<n && j+1<n){
            rightDiagonal=solve(i+1,j+1,matrix);
        }
        return dp[i][j]=matrix[i][j]+min({leftDiagonal,down,rightDiagonal});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        dp.assign(n,vector<ll>(n,LLONG_MAX));
        ll minSum=LLONG_MAX;
        for(int i=0;i<n;i++){
            minSum=min(minSum,solve(0,i,matrix));
        }
        return (int)minSum;

        
    }
};