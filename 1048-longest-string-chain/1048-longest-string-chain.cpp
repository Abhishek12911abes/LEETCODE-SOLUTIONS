class Solution {
public:
    int n;
    int dp[1001][1001];
    bool isPredecessor(string &s , string &t){
        if(s.size()-t.size()!=1){
            return false;
        }
        int i=0,j=0;
        int p=s.size();
        int q=t.size();
        while(j<q && i<p){
            if(t[j]==s[i]){
                j++;
            }
            i++;
        }
        return j==q;
    }
    int solve(vector<string>& words , int prevIdx , int currIdx){
        if(currIdx>=n){
            return 0;
        }
        if(dp[prevIdx+1][currIdx]!=-1){
            return dp[prevIdx+1][currIdx];
        }
        int skip=0,take=0;

        skip=solve(words,prevIdx,currIdx+1);

        if(prevIdx==-1 || (isPredecessor(words[currIdx],words[prevIdx]) && words[currIdx].size()-words[prevIdx].size()==1)){
            take=1+solve(words,currIdx,currIdx+1);
        }

        return dp[prevIdx+1][currIdx]=max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();

        sort(begin(words),end(words),[&](auto &a , auto &b){
            return a.size()<b.size();
        });

        memset(dp,-1,sizeof(dp));

        return solve(words,-1,0);
        
    }
};