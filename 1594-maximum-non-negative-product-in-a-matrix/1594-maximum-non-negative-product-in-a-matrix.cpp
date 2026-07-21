class Solution {
public:
    int m,n;
    typedef long long ll;
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int mod=1e9+7;

        vector<vector<pair<ll,ll>>>dp(m,vector<pair<ll,ll>>(n));

        dp[0][0]={grid[0][0],grid[0][0]};

        //filling first row;

        for(int i=1;i<n;i++){
            dp[0][i].first=dp[0][i-1].first*grid[0][i];
            dp[0][i].second=dp[0][i-1].second*grid[0][i];
        }

        // filling first col;

        for(int j=1;j<m;j++){
            dp[j][0].first=dp[j-1][0].first*grid[j][0];
            dp[j][0].second=dp[j-1][0].second*grid[j][0];
        }
        
        // filling 2D Dp table of pair

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll upmax=dp[i-1][j].first;
                ll upmin=dp[i-1][j].second;
                ll leftmax=dp[i][j-1].first;
                ll leftmin=dp[i][j-1].second;

                dp[i][j].first=max({upmax*grid[i][j], upmin*grid[i][j] , leftmax*grid[i][j] , leftmin*grid[i][j]});

                dp[i][j].second=min({upmax*grid[i][j], upmin*grid[i][j] , leftmax*grid[i][j] , leftmin*grid[i][j]});
            }
        }

        auto[maxProd,minProd]=dp[m-1][n-1];

        return maxProd<0?-1:(maxProd%mod);
    }
};