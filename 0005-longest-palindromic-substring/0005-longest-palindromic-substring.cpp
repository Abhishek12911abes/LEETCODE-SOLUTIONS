class Solution {
public:
    int start_i=-1;
    int maxLen=-1;
    void expand(int i , int j , string& s){


            while(i>=0 && j<s.size() && s[i]==s[j]){
                if(j-i+1>maxLen){
                    maxLen=j-i+1;
                    start_i=i;
                }
                i--,j++;
            }
            
        }
    string longestPalindrome(string s) {

        int n=s.size();
        // Approach 1 ) DP table
        // vector<vector<bool>>dp(n,vector<bool>(n));

        // for(int i=0;i<n;i++){
        //     dp[i][i]=true;
        // }

        // for(int L=2;L<=n;L++){
        //     for(int i=0;i+L-1<n;i++){
        //         int j=i+L-1;
        //         if(L==2){
        //             if(s[i]==s[j]){
        //                 dp[i][j]=true;
        //             }
        //         }
        //         else{
        //             if(s[i]==s[j] && dp[i+1][j-1]==true){
        //                 dp[i][j]=true;
        //             }
        //         }
        //     }
        // }

        // int start_i=-1;
        // int maxLen=-1;

        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(dp[i][j]){
        //             if(j-i+1>maxLen){
        //                 maxLen=j-i+1;
        //                 start_i=i;
        //             }
        //         }
        //     }
        // }
        // return s.substr(start_i,maxLen);

        // Approach 2 ) Using Center Expansion


        for(int i=0;i<n;i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }
        return s.substr(start_i,maxLen);
        
    }
};