class Solution {
public: 
    // int m,n;
    // int dp[101][101];
    // int solve(vector<vector<int>>& grid , int m ,int n , int i , int j){
    //     if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1){
    //         return 0;
    //     }
    //     if(i==m-1 && j==n-1){
    //         return 1;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     long long ways=0;
    //     int right=ways+solve(grid,m,n,i,j+1);
    //     int down=ways+solve(grid,m,n,i+1,j);

    //     return dp[i][j]=right+down;

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        // Recursion + Memoization

        int m=grid.size();
        int n=grid[0].size();
        // memset(dp,-1,sizeof(dp));
        // return solve(obstacleGrid,m,n,0,0);
        
        // Bottom Up

        vector<vector<int>>dp(m,vector<int>(n));
        // grid[0][0]=1;

        // filling first row;

        for(int i=0;i<n;i++){
            if(i>=1 && grid[0][i-1]==1){
                dp[0][i]=0;
                grid[0][i]=1;
            }
            else if(grid[0][i]==1){
                dp[0][i]=0;
            }
            else{
                dp[0][i]=1;
            }
        }

        // Filling first col;

        for(int j=0;j<m;j++){
            if(j>=1 && grid[j-1][0]==1){
                dp[j][0]=0;
                grid[j][0]=1;
            }
            else if(grid[j][0]==1){
                dp[j][0]=0;
            }
            else{
                dp[j][0]=1;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];

    }
};