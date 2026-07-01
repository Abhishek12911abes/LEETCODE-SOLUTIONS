class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));

        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=L+i-1;
                if(L==2){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }
                else if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        int maxLen=-1,start_i=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==true){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        start_i=i;
                    }
                }
            }
        }
        return s.substr(start_i,maxLen);
        
    }
};