class Solution {
public:
    int n;
    int dp[201][201];
    const int INF = 1e9;

    int solve(vector<vector<int>>& triangle, int i, int j) {

        if(i == n-1)
            return triangle[i][j];

        if(dp[i][j] != INF)
            return dp[i][j];

        return dp[i][j] =
            triangle[i][j] +
            min(solve(triangle,i+1,j),
                solve(triangle,i+1,j+1));
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        n = triangle.size();

        fill(&dp[0][0], &dp[0][0] + 201*201, INF);

        return solve(triangle,0,0);
    }
};