class Solution {
public:
    int n,m;
    typedef long long ll;
    int dp[201][201];
    ll solve(int n , int m , int i , int j , vector<vector<int>>& grid){
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(i<0 || j<0 || i>=n || j>=m){
            return INT_MAX; // invalid path hai toh INT_MAX bhej do
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        ll right=grid[i][j]+solve(n,m,i,j+1,grid);
        ll down=grid[i][j]+solve(n,m,i+1,j,grid);

        return dp[i][j]= min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        memset(dp,-1,sizeof(dp));

        return solve(n,m,0,0,grid);
        
    }
};