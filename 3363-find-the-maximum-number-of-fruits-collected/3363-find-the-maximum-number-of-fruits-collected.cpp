class Solution {
public:
    int n;
    int dp[1001][1001];
    int child1(vector<vector<int>>& fruits){
        int count=0;
        for(int i=0;i<n;i++){
            count+=fruits[i][i];
        }
        return count;
    }
    int child2(int i , int j , vector<vector<int>>& fruits){
        if(i+1>n || j-1<0 || j+1>n){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0; // as it is collected by child1
        }
        if(i==j || i>j){
            return 0; // diagonal ko cross nhi kr skta cuz wo n-1 moves se [n-1][n-1] tak nhi pahuch paega;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int dir1=fruits[i][j]+child2(i+1,j-1,fruits);
        int dir2=fruits[i][j]+child2(i+1,j,fruits);
        int dir3=fruits[i][j]+child2(i+1,j+1,fruits);

        return dp[i][j]=max({dir1,dir2,dir3});
    }

    int child3(int i , int j , vector<vector<int>>& fruits){
        if(i-1<0 || i+1>n || j+1>n){
            return 0;
        }
        if(i==n-1 && j==n-1){
            return 0; // as it is collected by child1
        }
        if(i==j || i<j){
            return 0; // diagonal ko cross nhi kr skta cuz wo n-1 moves se [n-1][n-1] tak nhi pahuch paega;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int dir1=fruits[i][j]+child3(i-1,j+1,fruits);
        int dir2=fruits[i][j]+child3(i,j+1,fruits);
        int dir3=fruits[i][j]+child3(i+1,j+1,fruits);

        return dp[i][j]=max({dir1,dir2,dir3});
    }

    
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();

        memset(dp,-1,sizeof(dp));
        int child1Collect=child1(fruits);

        int child2Collect=child2(0,n-1,fruits);

        int child3Collect=child3(n-1,0,fruits);

        return child1Collect+child2Collect+child3Collect;

        
    }
};