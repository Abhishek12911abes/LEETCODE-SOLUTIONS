class Solution {
public:
    int m,n;
    typedef long long ll;
    int mod=1e9+7;
    vector<vector<pair<ll,ll>>>dp;
    pair<ll,ll>solve(int i , int j , vector<vector<int>>& grid){
        if(i==m-1 && j==n-1){
            return {grid[i][j],grid[i][j]};
        }
        
        if(dp[i][j]!=make_pair(LLONG_MIN,LLONG_MAX)){
            return dp[i][j];
        }

        ll maxVal=LLONG_MIN;
        ll minVal=LLONG_MAX;

        if(i+1<m){
            auto[downmax,downmin]=solve(i+1,j,grid);
            maxVal=max({maxVal,downmax*grid[i][j],downmin*grid[i][j]});
            minVal=min({minVal,downmax*grid[i][j],downmin*grid[i][j]});
        }

        if(j+1<n){
            auto[rightmax,rightmin]=solve(i,j+1,grid);
            maxVal=max({maxVal,rightmax*grid[i][j],rightmin*grid[i][j]});
            minVal=min({minVal,rightmax*grid[i][j],rightmin*grid[i][j]});
        }

        return dp[i][j]= {maxVal,minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        dp=vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));

        auto[maxProd,minProd]=solve(0,0,grid);

        return maxProd<0?-1:(maxProd%mod);



        // Bottom Up

        // int mod=1e9+7;
        // vector<vector<pair<ll,ll>>>dp(m,vector<pair<ll,ll>>(n));

        // dp[0][0]={grid[0][0],grid[0][0]};

        // //filling first row;

        // for(int i=1;i<n;i++){
        //     dp[0][i].first=dp[0][i-1].first*grid[0][i];
        //     dp[0][i].second=dp[0][i-1].second*grid[0][i];
        // }

        // // filling first col;

        // for(int j=1;j<m;j++){
        //     dp[j][0].first=dp[j-1][0].first*grid[j][0];
        //     dp[j][0].second=dp[j-1][0].second*grid[j][0];
        // }
        
        // // filling 2D Dp table of pair

        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         ll upmax=dp[i-1][j].first;
        //         ll upmin=dp[i-1][j].second;
        //         ll leftmax=dp[i][j-1].first;
        //         ll leftmin=dp[i][j-1].second;

        //         dp[i][j].first=max({upmax*grid[i][j], upmin*grid[i][j] , leftmax*grid[i][j] , leftmin*grid[i][j]});

        //         dp[i][j].second=min({upmax*grid[i][j], upmin*grid[i][j] , leftmax*grid[i][j] , leftmin*grid[i][j]});
        //     }
        // }

        // auto[maxProd,minProd]=dp[m-1][n-1];

        // return maxProd<0?-1:(maxProd%mod);
    }
};