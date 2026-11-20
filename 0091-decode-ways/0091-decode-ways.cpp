class Solution {
public:
    int n;
    int dp[101];
    int solve(string& s , int idx){
        if(idx>=n){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int one=0,two=0;
        if(s[idx]!='0'){
            one+=solve(s,idx+1);
        }
        if(idx+1<n){
            int number=(s[idx]-'0')*10+(s[idx+1]-'0');
            if(number>=10 && number<=26){
                two+=solve(s,idx+2);
            }
        }
        return dp[idx]=one+two;
    }
    int numDecodings(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
        
    }
};