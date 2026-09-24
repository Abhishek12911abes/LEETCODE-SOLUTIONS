class Solution {
public:
    int n;
    int dp[101];
    int solve(string& s, int idx){
        if(idx>=n){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int num;
        if(idx+1<n){
            num=(s[idx]-'0')*10+(s[idx+1]-'0');
        }
        int oneChar=0,twoChar=0;

        if(s[idx]!='0'){
            oneChar=solve(s,idx+1);
        }
        if(num>=10 && num<=26){
            twoChar=solve(s,idx+2);
        }

        return dp[idx]=oneChar+twoChar;
    }
    int numDecodings(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
        
        // s='12'

        // AB
        // L
    }
};