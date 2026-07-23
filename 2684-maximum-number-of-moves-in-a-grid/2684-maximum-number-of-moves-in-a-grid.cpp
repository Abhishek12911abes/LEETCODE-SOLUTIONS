class Solution {
public:
    int m,n;
    int dp[1001][1001];
    int solve(int j , int i , vector<vector<int>>& grid ){
        if(i<0 || j<0 || i>=m || j>=n){
            return INT_MIN;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j==n-1){
            return 0;
        }

        int upDiag = 0, right = 0, downDiag = 0;

        int currVal=grid[i][j];

        if((i-1>=0 && j+1<n) && grid[i-1][j+1]>currVal){
            upDiag=1+solve(j+1,i-1,grid);
        }
        if(j+1<n && grid[i][j+1]>currVal){
            right=1+solve(j+1,i,grid);
        }
        if((i+1<m && j+1<n) && grid[i+1][j+1]>currVal){
            downDiag=1+solve(j+1,i+1,grid);
        }

        return dp[i][j]=max({upDiag,right,downDiag});

    }
    int maxMoves(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();

        memset(dp,-1,sizeof(dp));

        int maxMoves=-1;

        for(int j=0;j<m;j++){
            maxMoves=max(maxMoves,solve(0,j,matrix)); // column hamesha 0 hona chahie baki i ki val 0 se m-1 tak ja skti hai
        }

        return maxMoves;

        
    }
};