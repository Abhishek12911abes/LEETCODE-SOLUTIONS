class Solution {
public: 
    int m,n;
    int dp[101][101];
    int solve(vector<vector<int>>& grid , int m ,int n , int i , int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long ways=0;
        int right=ways+solve(grid,m,n,i,j+1);
        int down=ways+solve(grid,m,n,i+1,j);

        return dp[i][j]=right+down;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(obstacleGrid,m,n,0,0);
        
    }
};