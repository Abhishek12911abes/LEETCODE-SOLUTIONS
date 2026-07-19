class Solution {
public:
    int n,m;
    // typedef long long ll;
    // int dp[201][201];
    // ll solve(int n , int m , int i , int j , vector<vector<int>>& grid){
    //     if(i==n-1 && j==m-1){
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0 || i>=n || j>=m){
    //         return INT_MAX; // invalid path hai toh INT_MAX bhej do
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     ll right=grid[i][j]+solve(n,m,i,j+1,grid);
    //     ll down=grid[i][j]+solve(n,m,i+1,j,grid);

    //     return dp[i][j]= min(right,down);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        // Recurson + Memoization 
        n=grid.size();
        m=grid[0].size();

        // memset(dp,-1,sizeof(dp));

        // return solve(n,m,0,0,grid);

        // Bottom Up

        vector<vector<int>>dp(n,vector<int>(m));

        dp[0][0]=grid[0][0];
        // filling first row;
        for(int i=1;i<m;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }

        // filling first col
        for(int j=1;j<n;j++){
            dp[j][0]=grid[j][0]+dp[j-1][0];
        }

        // filling 2d dp table
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
        
    }
};