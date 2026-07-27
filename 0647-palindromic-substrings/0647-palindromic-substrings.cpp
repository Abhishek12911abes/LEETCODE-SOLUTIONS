class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();

        vector<vector<bool>>dp(n,vector<bool>(n));

        for(int i=0;i<n;i++){
            dp[i][i]=true; // 1 Length ka char hamesha pal hota hai
        }

        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(L==2){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }
                else{
                    dp[i][j]=s[i]==s[j] && dp[i+1][j-1];
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]){
                    count++;
                }
            }
        }
        return count;
        
    }
};